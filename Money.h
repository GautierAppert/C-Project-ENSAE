#ifndef MONEY_H
#define MONEY_H

#include <QGraphicsTextItem>
#include <QFont>



// The Money class, to manage the amount of money that the player will earn
class Money : public QGraphicsTextItem {

public:
    // Constructor
    Money(QGraphicsItem * parent=0);
    // Increase the amount of money by 1 (used when an enemy is killed)
    void increase();
    // Decrease the amount of money (used when a spaceship is bought)
    void decrease(int price);
    // Accessor of money
    int getMoney();

private :
    // Amount of money of the player
    int money;

};



#endif // MONEY_H
