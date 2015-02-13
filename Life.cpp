#include "Life.h"
#include "Game.h"



// There is an external global object called game
extern Game * game;

// Constructor
Life::Life(QGraphicsItem *parent) : QGraphicsTextItem(parent) {

    // Initialize the number of lifes to 10
    life = 10;

    // Display the number of lifes on the screen
    setPlainText(QString::number(life));

    // Some parameters : color, font, size
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",24));

}

// Decrease the number of lifes of the player (used when an enemy reaches the left of the screen)
void Life::decrease() {

    // Decrease the number of lifes by 1
    life--;

    // Update the display of the number of lifes
    setPlainText(QString::number(life));

    // If the number of lifes is 0, then it is a GAME OVER !
    if(life==0) {
        // Play the Game Over sound
        game->gameOverSound->play();
        // Stop the game music
        game->background->stop();
        // Call the destructor of the view
        game->~QGraphicsView();
        // Create a box with a Game Over message and the final score of the player
        QMessageBox::information(0, "GAME OVER", "<B><FONT COLOR='#000000'>GAME OVER ! Votre score final est de : </FONT></B>" + QString::number(game->score->getScore()));
        // Once we close the Game Over box, we quit the app
        qApp->quit();
    }

}
