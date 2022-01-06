// Starting Point of application

// RWindow Class
#include "rwindow.h"

// QApplication for Running App
#include <QApplication>
#include<QAction>

int main(int argc, char *argv[])
{
    // Instance of app and window
    QApplication rnote_qt(argc, argv);
    RWindow mainwindow;

    // Connecting Exit Action to QApp close
    QAction* exitAction = mainwindow.getExitAction();
    QAction::connect(exitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    // Setting main window Icon
    mainwindow.setWindowIcon(QIcon(":/icons/icon1.ico"));

    // Executing the app
    mainwindow.show();
    return rnote_qt.exec();
}
