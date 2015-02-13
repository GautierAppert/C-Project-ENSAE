#include "OpenWindow.h"
#include "Game.h"



// In order to create the game
Game * game;



// Constructor
OpenWindow::OpenWindow() {

    // Size of the window
    setFixedSize(800,700);
    // Background of the window
    setStyleSheet("background-image: url(:/images/BG.jpg)");

    //----- The PLAY button -----//
    // Create the button, using the QPushButton class from Qt
    playButton = new QPushButton("",this);
    // Characteristics of the button : cursor, image, size, position on the screen
    playButton->setCursor(Qt::PointingHandCursor);
    playButton->setIcon(QIcon(":/images/play.jpg"));
    playButton->setIconSize(QSize(200,100));
    playButton->setMinimumWidth(200);
    playButton->setMinimumHeight(100);
    playButton->move(300, 400);
    // Do the function onClickPlay() when we click on the PLAY button
    QObject::connect(playButton, SIGNAL(clicked()), this , SLOT(onClickPlay()));

    //----- The INSTRUCTIONS button -----//
    // Create the button, using the QPushButton class from Qt
    instruButton = new QPushButton("",this);
    // Characteristics of the button : cursor, image, size, position on the screen
    instruButton->setCursor(Qt::PointingHandCursor);
    instruButton->setIcon(QIcon(":/images/instruction.jpg"));
    instruButton->setIconSize(QSize(200,100));
    instruButton->setMinimumWidth(200);
    instruButton->setMinimumHeight(100);
    instruButton->move(300,550);
    // Do the function onClickInstru() when we click on the INSTRUCTIONS button
    QObject::connect(instruButton, SIGNAL(clicked()), this , SLOT(onClickInstru()));

}

// What happens when we click on the PLAY button
void OpenWindow::onClickPlay() {

    // Begin to play : we create a new game, using our Game class
    game = new Game();

    // Delete the opening window
    delete this;

}

// What happens when we click on the INSTRUCTIONS button
void OpenWindow::onClickInstru() {

    // Explain the rules of our game
    QMessageBox::information(0,"INSTRUCTIONS", "<B><FONT COLOR='#000000'>Des \
                             vaisseaux spatiaux attaquent votre base ! Vous \
                             devez la protéger ! Utilisez les touches HAUT et BAS \
                             afin de vous déplacer sur la base, et la touche ESPACE \
                             pour tirer sur les vaisseaux ennemis. Soyez rapide : chaque \
                             ennemi parvenant à atteindre votre base vous fera perdre \
                             une vie ! Chaque vaisseau détruit vous rapportera 1$. Cet \
                             argent vous permettra d'acheter des vaisseaux alliés qui, \
                             une fois placés dans l'espace, vont vous aider dans votre \
                             mission. Chaque type d'allié à un prix, une vitesse et une \
                             durée de vie différente. </FONT></B>");

}
