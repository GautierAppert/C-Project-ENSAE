#include "ShipSimple.h"



// Constructor
ShipSimple::ShipSimple() {

    // Initialize speed
    speed = 1000 ; // It will launch a shoot every second

    // Initialize life
    life = 30000; // It will stay on the scene 30 seconds

    // Select the image of the ship, from Resources files
    setPixmap(QPixmap(":/images/basic1.png"));


    //----- Management of the attacks and the life -----//

    // Create a timer, using the QTimer class from Qt
    QTimer * timer = new QTimer();
    // Do the launchShoot() function at each timeout of the timer
    connect(timer,SIGNAL(timeout()),this,SLOT(launchShoot()));
    // Start the timer
    timer->start(speed);

    // Create another timer
    QTimer * timer2 = new QTimer();
    // Do the end() function (which will delete the ship) when there is a timeout
    connect(timer2,SIGNAL(timeout()),this,SLOT(end()));
    // Start the timer
    timer2->start(life);

}
