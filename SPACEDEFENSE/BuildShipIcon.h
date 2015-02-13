#ifndef BUILDSHIPICON_H
#define BUILDSHIPICON_H

#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>



// The BuildShipIcon class, for the "ships buttons" at the bottom of the
// screen. If the player has enough money, he can buy and build spaceships
// from these buttons.

class BuildShipIcon: public QGraphicsPixmapItem {

public:
    // Constructor
    BuildShipIcon(QGraphicsItem * parent=0);
    // Make the player focusable again (after clicking on the icon)
    void playerFocus();
    // Play an error sound if the player tries to buy a spaceship
    // but does not have enough money
    void playErrorSound();

};



#endif // BUILDSHIPICON_H
