#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //QLabel label("0");
    w.MainWindow::show();
    //label.show();

    return a.exec();
}
