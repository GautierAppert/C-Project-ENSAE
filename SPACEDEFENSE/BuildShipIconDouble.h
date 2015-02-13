#ifndef BUILDSHIPICONDOUBLE_H
#define BUILDSHIPICONDOUBLE_H

#include "BuildShipIcon.h"
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>



// The BuildShipIconDouble class for the Double spaceship's icon
// It inherits from the BuildShipIcon class

class BuildShipIconDouble : public BuildShipIcon {

public:
    // Constructor
    BuildShipIconDouble();
    // What happens when we click on the icon
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};



#endif // BUILDSHIPICONDOUBLE_H
