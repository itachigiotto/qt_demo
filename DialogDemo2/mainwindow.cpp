#include <QAction>
#include <QMenuBar>
#include <QDialog>
#include <QDebug>
#include <QToolBar>
#include <QLabel>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"),tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered,
            this,       &MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    UserAgeDialog *dialog = new UserAgeDialog(this);
    connect(dialog,&UserAgeDialog::userAgeChanged,
            this,  &MainWindow::setUserAge);
    dialog->show();
}

void MainWindow::setUserAge(int age)
{

    qDebug() << age;
    this->setText(QString("Your age is %1").arg(QString::number(age)));
}
