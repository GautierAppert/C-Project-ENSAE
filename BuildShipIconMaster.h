#ifndef BUILDSHIPICONMASTER_H
#define BUILDSHIPICONMASTER_H

#include "BuildShipIcon.h"
#include<QGraphicsPixmapItem>
#include<QGraphicsSceneMouseEvent>



// The BuildShipIconMaster class for the Master spaceship's icon
// It inherits from the BuildShipIcon class

class BuildShipIconMaster : public BuildShipIcon {

public:
    // Constructor
    BuildShipIconMaster();
    // What happens when we click on the icon
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

};



#endif // BUILDSHIPICONMASTER_H
