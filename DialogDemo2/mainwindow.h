#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "useragedialog.h"

class MainWindow : public QMainWindow, public QLabel
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void open();
    void setUserAge(int age);
    QAction *openAction;
};

#endif // MAINWINDOW_H
