#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>

class CustomButton :public QPushButton
{
    Q_OBJECT
public:
    CustomButton(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);
};

class CustomButtonEx :public CustomButton
{
    Q_OBJECT
public:
    CustomButtonEx(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);
};

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    CustomWidget(QWidget *parent = 0);
protected:
    void mousePressEvent(QMouseEvent *event);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    //~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
