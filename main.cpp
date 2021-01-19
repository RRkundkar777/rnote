// Main file Executable

// RWindow Class
#include "rwindow.h"

// QApplication for Running App
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    RWindow window;
    window.show();

    return app.exec();
}
