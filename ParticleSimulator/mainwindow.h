#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <chrono>
#include <thread>
#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QTimer>
#include "controller.h"
#include "myellips.h"

using namespace std::this_thread;     // sleep_for, sleep_until
//using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using namespace std::chrono; // nanoseconds, system_clock, seconds

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
//Contructors and destructors**************************************************************
    explicit MainWindow(QWidget *parent = nullptr, int particleCount = 2);
    ~MainWindow();
//Getters and setters**********************************************************************

//Overloaded operators*********************************************************************

//Signals and Slots************************************************************************
public slots:
    void updatePositions(); //Updates the positions of graphics objects in
                            //response to update of particle positions
                            // in the controller object


//Member functions*************************************************************************
    void advance();
private:
    MyEllips * getPointer(MyEllips * item) const;
    QTimer *_timer;

//Data members*****************************************************************************
private:
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
    Controller *_c;

    QVector<Particle *> *_pList;
    QVector<MyEllips *> _shapeList;




};

#endif // MAINWINDOW_H



