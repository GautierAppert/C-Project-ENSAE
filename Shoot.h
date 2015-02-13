#ifndef SHOOT_H
#define SHOOT_H

#include "Enemy.h"
#include"Shoot.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo> // for typeid()
#include <QPixmap>



// The Shoot class, for the bullets launched by the player and the spaceships
class Shoot: public QObject, public QGraphicsPixmapItem {

    Q_OBJECT // Required for Qt, because we use public slots

public:
    // Constructor
    Shoot(QGraphicsItem * parent=0);

public slots:
    // Set the bullet's movements
    void shootMove();

};



#endif // SHOOT_H
