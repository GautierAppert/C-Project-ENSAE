#include "BuildShipIconSimple.h"
#include "Game.h"



// There is an external global object called game
extern Game * game ;

// Constructor
BuildShipIconSimple::BuildShipIconSimple() {

    // Select the image of the ship, from Resources files
    setPixmap(QPixmap(":/images/basic1.png"));

    // Set the position of the icon on the screen
    setPos(x()+270,y()+545);

}

// What happens when we click on the icon
void BuildShipIconSimple::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    // If the player has enough money (10 or more) to buy the ship,
    // he can buy it
    if(game->money->getMoney()>=10){
        // In this case, money decreases by 10, which is the price of the Simple ship
        game->money->decrease(10);
        // testShipSimple=true in order to put the ship as the focusable item (see game.cpp)
        game->testShipSimple = true;
        game->setCursor(QString(":/images/basic1.png"));
    }
    else{
        // If he does not have enough money to buy the ship, he can not buy it
        // and he hears an error sound
        playErrorSound();
    }
    // Put back the player's ship as the focusable item
    playerFocus();

}
