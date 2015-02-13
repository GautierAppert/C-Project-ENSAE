#include "BuildShipIconDouble.h"
#include "Game.h"



// There is an external global object called game
extern Game * game ;

// Constructor
BuildShipIconDouble::BuildShipIconDouble() {

    // Select the image of the ship, from Resources files
    setPixmap(QPixmap(":/images/double1.png"));

    // Set the position of the icon on the screen
    setPos(x()+470,y()+545);

}

// What happens when we click on the icon
void BuildShipIconDouble::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    // If the player has enough money (20 or more) to buy the ship,
    // he can buy it
    if(game->money->getMoney()>=20){
        // In this case, money decreases by 10, which is the price of the Double ship
        game->money->decrease(20);
        // testShipDouble=true in order to put the ship as the focusable item (see game.cpp)
        game->testShipDouble = true;
        game->setCursor(QString(":/images/double1.png"));
    }
    else{
        // If he does not have enough money to buy the ship, he can not buy it
        // and he hears an error sound
        playErrorSound();
    }
    // Put back the player's ship as the focusable item
    playerFocus();

}
