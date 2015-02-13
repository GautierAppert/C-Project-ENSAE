#include "BuildShipIcon.h"
#include "Game.h"



// There is an external global object called game
extern Game * game ;

// Constructor
BuildShipIcon::BuildShipIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

}

// Make the player focusable again (after clicking on the icon)
void BuildShipIcon::playerFocus() {
    // Put back the player's ship as the focusable item. Otherwise, we could not
    // move it anymore (using the keyboard) after clicking on a ship's icon
    game->player->setFlag(QGraphicsItem::ItemIsFocusable);
    game->player->setFocus();
}

// Play an error sound if the player tries to buy a spaceship
// but does not have enough money
void BuildShipIcon::playErrorSound() {
    // If necessary, we have to put back the sound to its beginning, otherwise
    // we will only hear a sound for the first error of the game
    if(game->errorSound->state() == QMediaPlayer::PlayingState) {
        game->errorSound->setPosition(0);
    }
    game->errorSound->play();
}
