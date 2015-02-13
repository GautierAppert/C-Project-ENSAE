#include "Money.h"



// Constructor
Money::Money(QGraphicsItem *parent) : QGraphicsTextItem(parent) {

    // Initialize the money to zero
    money = 0;

    // Display the available money on the screen
    setPlainText(QString::number(money));

    // Some parameters : color, font, size
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",24));

}

// Increase the amount of money by 1 (used when an enemy is killed)
void Money::increase() {

    money++;

    // Update the display of the money
    setPlainText(QString::number(money));

}

// Decrease the amount of money (used when a spaceship is bought)
void Money::decrease(int price) {

    // The player has to pay the price of the spaceship (which will be 10, 20 or 40 dollars)
    money = money - price;

    // Update the display of the money
    setPlainText(QString::number(money));

}

// Accessor of money
int Money::getMoney() {

    return money;

}
