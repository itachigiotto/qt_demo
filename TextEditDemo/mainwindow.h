#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include <QCloseEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //void open();

    QAction *openAction;
    QAction *saveAction;

    QTextEdit *textEdit;

    void openFile();
    void saveFile();
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
