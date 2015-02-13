#include "Player.h"



// Constructor
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {

    // Create a new QMediaPlayer for the sound that the Player will make when he will attack
    shootSound = new QMediaPlayer();

    // Select the sound, from Resources files
    shootSound->setMedia(QUrl("qrc:/music/tir.mp3"));

    // Select the image of the Player, from Resources files
    setPixmap(QPixmap(":/images/theplayer.png"));

}



// Qt function that will make the Player react to some events on the keyboard
void Player::keyPressEvent(QKeyEvent *event) {

    // What happens if the UP button of the keyboard is pressed
    if(event->key() == Qt::Key_Up) {
        // If the Player is not at the top of the screen, he moves up
        if(pos().y() > 0) {
            setPos(x(),y()-25);
        }
    }

    // What happens if the DOWN button of the keyboard is pressed
    else if(event->key() == Qt::Key_Down) {
        // If the Player is not at the bottom of the screen, he moves down
        if(pos().y()+100 < 470) {
            setPos(x(),y()+25);
        }
    }

    // What happens if the SPACE button of the keyboard is pressed
    else if (event->key() == Qt::Key_Space) {

        // In this case, the player will attack enemies

        //----- First, we create the shoot that the Player will launch -----//
        // We create this shoot, using our Shoot class
        Shoot * shoot = new Shoot();
        // We ajust the position of this shoot (with respect to the Player image)
        shoot->setPos(x()+100,y()+48);
        // We add it to the scene
        scene()->addItem(shoot);

        //----- Then, the Player makes a sound when the shoot is launched -----//
        // If necessary, we have to put back the sound to its beginning, otherwise
        // we will only hear a sound for the first shoot of the game
        if(shootSound->state() == QMediaPlayer::PlayingState) {
            shootSound->setPosition(0);
        }
        // We play the sound
        shootSound->play();
    }

}



// Add enemies to the scene (they will come in front of the player's ship, once it is created)
void Player::generateEnemy() {
    // We create the enemy, using our Enemy class
    Enemy * enemy = new Enemy();
    // We add this enemy to the scene
    scene()->addItem(enemy);

}
