#include <QDebug>
#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent)
    : QPushButton(parent)
{
    connect(this, &CustomButton::clicked,
            this, &CustomButton::onButtonClicked);
}

CustomButton::~CustomButton()
{

}

void CustomButton::onButtonClicked()
{
    qDebug() << "You clicked this!";
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "left";
    }
    else
    {
        QPushButton::mousePressEvent(event);
    }

}
