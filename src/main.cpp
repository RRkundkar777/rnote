// Starting Point of application

// RWindow Class
#include "rwindow.h"

// QApplication for Running App
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication rnote_qt(argc, argv);
    RWindow mainwindow;
    mainwindow.show();
    return rnote_qt.exec();
}
