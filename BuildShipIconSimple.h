#ifndef BUILDSHIPICONSIMPLE_H
#define BUILDSHIPICONSIMPLE_H

#include "BuildShipIcon.h"
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>



// The BuildShipIconSimple class for the Simple spaceship's icon
// It inherits from the BuildShipIcon class

class BuildShipIconSimple : public BuildShipIcon {

public:
    // Constructor
    BuildShipIconSimple();
    // What happens when we click on the icon
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};



#endif // BUILDSHIPICONSIMPLE_H
