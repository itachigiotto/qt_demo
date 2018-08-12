#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>

class CustomButton : public QPushButton
{
    Q_OBJECT

public:
    CustomButton(QWidget *parent = 0);
    ~CustomButton();
private:
    void onButtonClicked();
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // CUSTOMBUTTON_H
