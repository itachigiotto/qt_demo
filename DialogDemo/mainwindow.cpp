#include <QAction>
#include <QMenuBar>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/document-open"),
                             tr("&Open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction,&QAction::triggered,
            this,      &MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
}

MainWindow::~MainWindow()
{
}

void MainWindow::open()
{
    //    QDialog dialog(this);
    //    dialog.setWindowTitle(tr("Hello, dialogs!"));
    //    dialog.exec();
    //    qDebug() << dialog.result();
    //    QDialog *dialog = new QDialog;
    //    dialog->setAttribute(Qt::WA_DeleteOnClose);
    //    dialog->setWindowTitle(tr("Hello, dialog!"));
    //    dialog->show();
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("Question"),
                                                  tr("Are you OK?"),
                                                  QMessageBox::Yes | QMessageBox::No,
                                                  QMessageBox::Yes)) {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
    } else {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
    }
}
