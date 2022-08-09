// application start point

#include <QApplication>
#include<QAction>
#include "rwindow.h"

int main(int argc, char *argv[])
{
    // instance of app and window
    QApplication rnote(argc, argv);
    RWindow mainwindow;

    // connecting exitaction to QApp close
    QAction* exitAction = mainwindow.getExitAction();
    QAction::connect(exitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    // set main window icon
    mainwindow.setWindowIcon(QIcon(":/icons/icon1.ico"));

    // executing the app
    mainwindow.show();
    return rnote.exec();
}
