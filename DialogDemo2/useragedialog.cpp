#include <QAction>
#include <QMenuBar>
#include <QDialog>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QSpinBox>
#include "useragedialog.h"


UserAgeDialog::UserAgeDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Enter your age: "));
    QSpinBox *spinBox = new QSpinBox(this);
    spinBox->setRange(0,130);
    void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
    connect(spinBox,spinBoxSignal,
            this,   &UserAgeDialog::ageChanged);
    spinBox->setValue(0);
    //qDebug() << spinBox->value();
    QPushButton *button = new QPushButton(tr("ok"),this);
    button->setGeometry(50,50,50,20);
    connect(button, &QPushButton::clicked,
            this,    &UserAgeDialog::accept);
}

UserAgeDialog::~UserAgeDialog()
{

}

void UserAgeDialog::accept()
{
    emit userAgeChanged(newAge);
    QDialog::accept();
}

void UserAgeDialog::ageChanged(int age)
{
    newAge = age;
    //qDebug() << newAge;
}

inline void UserAgeDialog::userAgeChanged(int age)
{
    newAge = age;
}
