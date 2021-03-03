#ifndef MYELLIPS_H
#define MYELLIPS_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include "particle.h"
#include <chrono>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
//using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using namespace std::chrono; // nanoseconds, system_clock, seconds

class MyEllips : public QGraphicsItem
{
public:
    MyEllips();
    MyEllips(Particle *particle);
    ~MyEllips();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
protected:
    void advance(int phase) override;
private:
    qreal x, y;
    Particle *_particle;
    QBrush _redBrush;
    QBrush _blueBrush;
    QPen _blackPen;
    QPainter *_painter;


};

#endif // MYELLIPS_H
