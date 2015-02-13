#ifndef OPENWINDOW_H
#define OPENWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QMainWindow>
#include <QBrush>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QMessageBox>



// The OpenWindow class, for the window that will be opened when the .exe will be launched

// In this window, we will only have two buttons :
//      - a PLAY button, in order to start a new game
//      - an INSTRUCTIONS button, which will lead to the rules of our game

class OpenWindow : public QMainWindow { // Here, we inherit from QMainWindow

    Q_OBJECT // Required for Qt, because we use public slots

public:
    // Constructor
    OpenWindow();

public slots:
    // What happens when we click on the PLAY button
    void onClickPlay();
    // What happens when we click on the INSTRUCTIONS button
    void onClickInstru();

private :
    // The PLAY button
    QPushButton *playButton;
    //  The INSTRUCTIONS button
    QPushButton *instruButton;

};



#endif // OPENWINDOW_H
