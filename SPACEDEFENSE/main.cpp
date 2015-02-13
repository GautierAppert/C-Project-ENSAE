#include <QApplication>
#include "OpenWindow.h"

// The main function of the project
int main(int argc, char *argv[]) {

    // Create the application, using the QApplication class (standard code line for Qt)
    QApplication a(argc, argv);

    // Create the open screen, using the OpenWindow class
    OpenWindow * window = new OpenWindow();
    // Show it
    window->show();

    return a.exec();

}
