#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QList>
#include <QPushButton>
#include "TuioDemo.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void grabMouseEvent(QMouseEvent *event);
    TuioDemo *app;
    void timerEvent(QTimerEvent *event);
private:
    Ui::MainWindow *ui;
    QPainter *painter;
    QList<QPoint> pointList;
    QPushButton *pushButton;
public slots:
    void foo();
};

#endif // MAINWINDOW_H
