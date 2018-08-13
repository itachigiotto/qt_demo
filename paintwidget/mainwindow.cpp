#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}

PaintedWidget::PaintedWidget(QWidget *parent) :
    QWidget(parent)
{
    resize(800,600);
    setWindowTitle(tr("Paint Demo"));
}

void PaintedWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    /*
    painter.drawLine(80, 100, 650, 500);
    painter.setPen(Qt::red);
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50, 150, 400, 200);
    */

    /*
    painter.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(50, 150, 200, 150);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(300, 150, 200, 150);
    */

    /*
    painter.setRenderHint(QPainter::Antialiasing, true);
    QLinearGradient linearGradient(60, 50, 200, 200);
    linearGradient.setColorAt(0.2, Qt::white);
    linearGradient.setColorAt(0.6, Qt::green);
    linearGradient.setColorAt(1.0, Qt::black);
    painter.setBrush(QBrush(linearGradient));
    painter.drawEllipse(50, 50, 200, 150);
    */

    /*
    painter.setRenderHint(QPainter::Antialiasing);

    const int r = 150;
    QConicalGradient conicalGradient(0, 0, 0);

    conicalGradient.setColorAt(0.0, Qt::red);
    conicalGradient.setColorAt(60.0/360.0, Qt::yellow);
    conicalGradient.setColorAt(120.0/360.0, Qt::green);
    conicalGradient.setColorAt(180.0/360.0, Qt::cyan);
    conicalGradient.setColorAt(240.0/360.0, Qt::blue);
    conicalGradient.setColorAt(300.0/360.0, Qt::magenta);
    conicalGradient.setColorAt(1.0, Qt::red);

    painter.translate(r, r);

    QBrush brush(conicalGradient);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(0, 0), r, r);
    */

    /*
    painter.fillRect(10, 10, 50, 100, Qt::red);
    painter.save();
    painter.translate(100, 0); // 向右平移 100px
    painter.fillRect(10, 10, 50, 100, Qt::yellow);
    painter.restore();
    painter.save();
    painter.translate(300, 0); // 向右平移 300px
    painter.rotate(30); // 顺时针旋转 30 度
    painter.fillRect(10, 10, 50, 100, Qt::green);
    painter.restore();
    painter.save();
    painter.translate(400, 0); // 向右平移 400px
    painter.scale(2, 3); // 横坐标单位放大 2 倍，纵坐标放大 3 倍
    painter.fillRect(10, 10, 50, 100, Qt::blue);
    painter.restore();
    painter.save();
    painter.translate(600, 0); // 向右平移 600px
    painter.shear(0, 1); // 横向不变，纵向扭曲 1 倍
    painter.fillRect(10, 10, 50, 100, Qt::cyan);
    painter.restore();
    */


    QPixmap pixmap("qt-logo.png");
    QBitmap bitmap("qt-logo.png");

}
