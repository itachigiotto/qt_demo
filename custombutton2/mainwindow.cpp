#include <QDebug>
#include <QVBoxLayout>
#include "mainwindow.h"


CustomButton::CustomButton(QWidget *parent) : QPushButton(parent)
{
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "CustomButton";
}

CustomButtonEx::CustomButtonEx(QWidget *parent) : CustomButton(parent)
{

}

void CustomButtonEx::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "CustomButtonEx";
}


CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{

}

void CustomWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "CustomWidget";
    //QWidget::mousePressEvent(event);
    event->ignore();
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    CustomWidget *widget = new CustomWidget(this);
    CustomButton *cb = new CustomButton(widget);
    cb->setText(tr("CustomButton"));
    CustomButtonEx *cbex = new CustomButtonEx(widget);
    cbex->setText(tr("CustomBottonEx"));
    QVBoxLayout *widgetLayout = new QVBoxLayout(widget);
    widgetLayout->addWidget(cb);
    widgetLayout->addWidget(cbex);
    this->setCentralWidget(widget);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "MainWindow";
}
