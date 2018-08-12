#ifndef USERAGEDIALOG_H
#define USERAGEDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QMainWindow>

class UserAgeDialog : public QDialog
{
    Q_OBJECT

public:
    UserAgeDialog(QWidget *parent = 0);
    ~UserAgeDialog();

    int newAge;

    void accept();
    void ageChanged(int Age);

signals:
    void userAgeChanged(int Age);
};

#endif // USERAGEDIALOG_H
