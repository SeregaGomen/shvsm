#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w; // Экземпляр основного окна

    w.show();
    return app.exec();
}
