#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QDebug>
#include <QTextEdit>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int port = 3333;
    startTimer(1000);
    app = new TuioDemo(port);

    pushButton = new QPushButton("Hello",this);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(foo()));
}
 void MainWindow::timerEvent(QTimerEvent *event)
 {
    qDebug() << "Timer ID:" << event->timerId();
    pointList.clear();
    std::list<TuioCursor*> cursorList = app->tuioClient->getTuioCursors();
    // Had to comment this one because it crashes the program
    // app->tuioClient->lockCursorList();
    for (std::list<TuioCursor*>::iterator iter = cursorList.begin(); iter!=cursorList.end(); iter++) {
        TuioCursor *tuioCursor = (*iter);
        std::cout << "in my qt cursor: " << (*iter)->getCursorID() << std::endl;

        std::list<TuioPoint> path = tuioCursor->getPath();
        for (std::list<TuioPoint>::iterator point = path.begin(); point!=path.end(); point++) {
            std::cout << "::" << point->getX() << "," << point->getY() << std::endl;
            pointList.push_back(QPoint(point->getX()*this->width(),point->getY()*height()));
        }
    }
    this->repaint();
 }

MainWindow::~MainWindow() {
    delete app;
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    qDebug() << event->button();
    pointList.push_back(event->pos());
    qDebug() << "list size: " << pointList.size();
    this->repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    qDebug() << "evento";
}
void MainWindow::grabMouseEvent(QMouseEvent *event) {
    qDebug() << "agarro";   
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    qDebug() << "repainting?";


    for (int i=0; i< pointList.size()-1; i++) {
        painter.drawLine(pointList.at(i), pointList.at(i+1));
        qDebug() << pointList.at(i);
    }
    //this->ui->textEdit->setText("hello");
}

void MainWindow::foo() {
    qDebug() << "foo";
}


