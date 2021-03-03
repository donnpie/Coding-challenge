

#include "vector.h"

dp::Vector::Vector() : _x(0), _y(0), _parent(nullptr)
{
    //qDebug() << "dp::Vector::Vector() constructor called on " << this;
}

dp::Vector::Vector(double x, double y)  : _x(x), _y(y), _parent(nullptr)
{
    //qDebug() << "dp::Vector::Vector(double x, double y) constructor called on " << this;
}

dp::Vector::Vector(double x, double y, Particle *parent) : _x(x), _y(y), _parent(parent)
{
    qDebug() << "dp::Vector::Vector(double x, double y, Particle *parent) constructor called on " << this;
}

dp::Vector::Vector(const dp::Vector &other)
{
    qDebug() << "dp::Vector::Vector(const dp::Vector &other) constructor called on " << this << ". Other is at " << &other;
    this->_x = other._x;
    this->_y = other._y;
    this->_parent = other._parent;
}

dp::Vector::~Vector()
{
    //qDebug() << "dp::Vector::~Vector() destructor called on " << this;
}

double dp::Vector::getX()
{
    return _x;
}

double dp::Vector::getY()
{
    return _y;
}

Particle *dp::Vector::getParent()
{
    return _parent;
}

void dp::Vector::setX(double x)
{
    _x = x;
}

void dp::Vector::setY(double y)
{
    _y = y;
}

void dp::Vector::setParent(Particle *parent)
{
    _parent = parent;
}

dp::Vector dp::Vector::operator+(const dp::Vector &otherVector) const
{
    //qDebug() << "dp::Vector::operator+(const dp::Vector &otherVector) called on " << this << ". Other is at " << &otherVector;
    dp::Vector v;
    v = *this;
    v.addVector(otherVector);
    return v;
}

void dp::Vector::addVector(const dp::Vector &otherVector)
{
    this->_x += otherVector._x;
    this->_y += otherVector._y;
}

void dp::Vector::operator=(const dp::Vector &otherVector)
{
    //qDebug() << "void dp::Vector::operator=(const dp::Vector &otherVector) called on " << this << ". Other is at " << &otherVector;
    this->_x = otherVector._x;
    this->_y = otherVector._y;
}

//dp::Vector dp::Vector::operator=(dp::Vector &otherVector) const
//{
//    otherVector._x = this->_x;
//    otherVector._y = this->_y;
//    return otherVector;
//}

dp::Vector dp::Vector::calcDeltaVector(const dp::Vector *otherVector) const
{
    dp::Vector v;
    //v = *this; //not sure why i added this line?
    v.setX(this->_x - otherVector->_x);
    v.setY(this->_y - otherVector->_y);
    v.setParent(otherVector->_parent);
    return v;
}

double dp::Vector::calcDistance(const dp::Vector &otherVector) const
{
    double d;
    d = sqrt(pow(this->_x - otherVector._x, 2) + pow(this->_y - otherVector._y, 2));
    return d;
}

void dp::Vector::scalarMultiplyMe(double scalar)
{
    this->_x = scalar * _x;
    this->_x = scalar * _x;
}

dp::Vector dp::Vector::scalarMultiply(double scalar) const
{
    dp::Vector v;
    v.setX(this->_x * scalar);
    v.setY(this->_y * scalar);
    return v;
}

double dp::Vector::calcLength()
{
    return sqrt(pow(_x, 2) + pow(_y, 2));
}

void dp::Vector::reverseDirection()
{
    this->_x = -_x;
    this->_y = -_y;
}

void dp::Vector::reset()
{
    this->_x = 0;
    this->_y = 0;
}

QDebug dp::operator<<(QDebug d, const dp::Vector &v)
{
    d << "x: " << v._x << "y: " << v._y << "Parent: " << v._parent;
    return d;
}



