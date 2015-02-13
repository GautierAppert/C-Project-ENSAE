#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include "Ship.h"
#include "BuildShipIconSimple.h"
#include "BuildShipIconDouble.h"
#include "BuildShipIconMaster.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QApplication>
#include<QPixmap>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QList>



// Constructor
Game::Game(QWidget *parent) {

    // Initialize the three booleans to FALSE (no ship has been bought at the
    // beginning of the game)
    testShipSimple = false;
    testShipDouble = false;
    testShipMaster = false;

    // Create the scene
    scene = new QGraphicsScene();

    // Fix the size of the scene (800*700)
    scene->setSceneRect(0,0,800,700);
    setScene(scene);

    // Set the background image of the game, from Resources files
    setBackgroundBrush(QBrush(QImage(":/images/BG2.jpg")));

    // Block scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

    // Fix the size of the view
    setFixedSize(800,700);


    //----- CREATION OF THE PLAYER -----//
    // Create the player
    player = new Player();
    // Set the initial position of the player
    player->setPos(0,200);
    // Make the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // Add the player to the scene
    scene->addItem(player);


    //---- INITIALIZE SHIPS ICONS -----//
    // Cursor is desactivated at the beginning of the game
    cursor = nullptr;
    // Set build to nullptr because no ship has been bought at the beginning of the game
    build = nullptr;
    setMouseTracking(true);
    // Create the three icons for the three ship builders, and add them to the scene
    BuildShipIconSimple * icon = new BuildShipIconSimple();
    scene->addItem(icon);

    BuildShipIconDouble * icon2 = new BuildShipIconDouble();
    scene->addItem(icon2);

    BuildShipIconMaster * icon3 = new BuildShipIconMaster();
    scene->addItem(icon3);


    //----- CREATE SCORE, LIFE AND MONEY -----//
    // Create the score
    score = new Score();
    // Add it to the scene
    scene->addItem(score);
    // Set its position
    score->setPos(score->x()+140,score->y()+637);

    // Create the money
    money = new Money();
    // Add it to the scene
    scene->addItem(money);
    // Set its position
    money->setPos(money->x()+140,money->y()+498);

    // Create the life
    life = new Life();
    // Add it to the scene
    scene->addItem(life);
    // Set its position
    life->setPos(life->x()+140,life->y()+567);



    //----- CREATE ENEMIES -----//
    // Create a new timer, using the QTimer class from Qt
    QTimer * timer = new QTimer();
    // Spawn a new enemy at each timeout of the timer
    QGraphicsScene::connect(timer,SIGNAL(timeout()),player,SLOT(generateEnemy()));
    // A new enemy will appear every 1.8 seconds (1800 milliseconds)
    timer->start(1800);


    //----- CREATE MUSICS -----//
    // Create the background music, by creating a new QMediaPlayer object
    // and selecting files from Resources
    background = new QMediaPlayer();
    background->setMedia(QUrl("qrc:/music/backgroundmusic.mp3"));
    // Play it
    background->play();

    // Create the error sound, by creating a new QMediaPlayer object
    // and selecting files from Resources
    errorSound = new QMediaPlayer();
    errorSound->setMedia(QUrl("qrc:/music/errorsound.mp3"));

    // Create the Game Over sound (played at the end of the game), by
    //creating a new QMediaPlayer object and selecting files from Resources
    gameOverSound = new QMediaPlayer();
    gameOverSound->setMedia(QUrl("qrc:/music/gameoversound.mp3"));


    // Show the game !
    show();

}

// A function to put an image as the cursor (used when a ship has been bought)
void Game::setCursor(QString filename) {
    // If there is alread a cursor, we delete it
    if(cursor) {
        scene->removeItem(cursor);
        delete cursor ;
    }
    // Then, we put as the cursor the image of the ship bought by the player (see the
    // three BuildShipIcon's .cpp files)
    cursor = new QGraphicsPixmapItem();
    cursor ->setPixmap(QPixmap(filename));
    scene->addItem(cursor);

}

// A function to make the cursor follow the mouse of the player
void Game::mouseMoveEvent(QMouseEvent *event) {
    if(cursor) {
        cursor->setPos(event->pos());
    }

}

// What happens when we click on the zone area (after having bought a ship)
void Game::mousePressEvent(QMouseEvent *event){

    // If we are indeed on the zone area (and not of the player's base for example)
    if(event->x() > 100 && event->x() < 700 && event->y() >0  && event->y() < 400) {

        // If a Simple Ship has been bought
        if(testShipSimple) {
            // Create a new ShipSimple, inside the build attribute
            build =  new ShipSimple();
            // Add it to the scene
            scene->addItem(build);
            // Set its position
            build->setPos(event->pos());
            // Remove the image that follow the mouse of the player
            scene->removeItem(cursor);
            // Set cursor and build to nullptr
            cursor = nullptr;
            build = nullptr;
            // Set the testShipSimple boolean to false
            testShipSimple = false;
        }

        // If a Double Ship has been bought
        if(testShipDouble) {
            // Create a new ShipDouble, inside the build attribute
            build =  new ShipDouble();
            // Add it to the scene
            scene->addItem(build);
            // Set its position
            build->setPos(event->pos());
            // Remove the image that follow the mouse of the player
            scene->removeItem(cursor);
            // Set cursor and build to nullptr
            cursor = nullptr;
            build = nullptr;
            // Set the testShipDouble boolean to false
            testShipDouble = false;
        }
        // If a Master Ship has been bought
        if(testShipMaster) {
            // Create a new ShipMaster, inside the build attribute
            build =  new ShipMaster();
            // Add it to the scene
            scene->addItem(build);
            // Set its position
            build->setPos(event->pos());
            // Remove the image that follow the mouse of the player
            scene->removeItem(cursor);
            // Set cursor and build to nullptr
            cursor = nullptr;
            build = nullptr;
            // Set the testShipMaster boolean to false
            testShipMaster = false;
        }

    }
    // If nothing has been bought :
    else {
        QGraphicsView::mousePressEvent(event);
    }

}
