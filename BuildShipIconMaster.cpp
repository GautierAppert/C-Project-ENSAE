#include "BuildShipIconMaster.h"
#include "Game.h"



// There is an external global object called game
extern Game * game ;

// Constructor
BuildShipIconMaster::BuildShipIconMaster() {

    // Select the image of the ship, from Resources files
    setPixmap(QPixmap(":/images/master1.png"));

    // Set the position of the icon on the screen
    setPos(x()+665,y()+545);

}

// What happens when we click on the icon
void BuildShipIconMaster::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    // If the player has enough money (40 or more) to buy the ship,
    // he can buy it
    if(game->money->getMoney()>=40){
        // In this case, money decreases by 40, which is the price of the Master ship
        game->money->decrease(40);
        // testShipMaster=true in order to put the ship as the focusable item (see game.cpp)
        game->testShipMaster = true;
        game->setCursor(QString(":/images/master1.png"));
    }
    else{
        // If he does not have enough money to buy the ship, he can not buy it
        // and he hears an error sound
        playErrorSound();
    }
    // Put back the player's ship as the focusable item
    playerFocus();

}
