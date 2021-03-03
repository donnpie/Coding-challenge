#include "myellips.h"

MyEllips::MyEllips() : x(0), y(0), _particle(nullptr)
{

}

MyEllips::MyEllips(Particle *particle) : x(0), y(0), _particle(particle)
{
    //these are not pointers
    _redBrush.setColor(Qt::red);
    _redBrush.setStyle(Qt::SolidPattern);
    _blueBrush.setColor(Qt::blue);
    _blueBrush.setStyle(Qt::SolidPattern);
    _blackPen.setColor(Qt::black);
    _blackPen.setWidth(3);

    _painter = new QPainter();
    //paint(_painter, new QStyleOptionGraphicsItem(), nullptr); //This did not work
    paint(_painter, nullptr, nullptr);
}

MyEllips::~MyEllips()
{
    qDebug() << "***MyEllips::~MyEllips() called on " << this;
    delete _painter;
    qDebug() << "***MyEllips::~MyEllips() end";
}

QRectF MyEllips::boundingRect() const
{
    return QRectF(0, 0, 20, 20);
}

void MyEllips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << "***void MyEllips::paint(QPainter *painter... called on " << this;
    //painter->fillRect(boundingRect(), QBrush(Qt::red)); //Fills rectangle not circle
    QString ftString = "";
    ftString = _particle->getForceType()->getForceTypeString();
    QRectF rect = boundingRect();
    if (ftString == "Attract")
    {
        //_painter->setBrush(_redBrush);
        painter->fillRect(rect, _redBrush);
        //paint(_painter, nullptr, nullptr);
    }
    else if (ftString == "Repel")
    {
        //_painter->setBrush(_blueBrush);
        painter->fillRect(rect, _blueBrush);
        //paint(_painter, nullptr, nullptr);
    }
    else {
        qDebug() << "Error in void MyEllips::paint(QPainter *painter... "
                 << "ForceTypeString value could not be recognised. check for typos";
        exit(-6);
    }

    painter->drawRect(rect);

    //delete option;
    qDebug() << "***void MyEllips::paint(QPainter *painter... end";
}

void MyEllips::advance(int phase)
{
    qDebug() << "***void MyEllips::advance(int phase) start";
    if (!phase) return;
    int x = static_cast<int>(_particle->getVector("Position")->getX());
    int y = static_cast<int>(_particle->getVector("Position")->getY());
    qDebug() << "Particle: " << _particle << "x: " << x << "y: " << y;
    //setPos(mapToParent(x, y));
    setPos(x, y);
    //paint here?
    //sleep_for(milliseconds(1000));
    qDebug() << "***void MyEllips::advance(int phase) end";

}
