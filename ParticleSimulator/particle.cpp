#include "particle.h"
#include "abstractforcetype.h"
#include "attractforcetype.h"
#include "repelforcetype.h"
#include "forcetypefactory.h"

//Contructors and destructors**************************************************************

Particle::Particle() : _mass(0), _size(0), _sizeToMassRatio(0),
                         _forceType(nullptr), _position(nullptr),
                         _velocity(nullptr), _acceleration(nullptr),
                         _netForce(nullptr)
{
    qDebug() << "Particle::Particle() constructor called on " << this;
}

Particle::Particle(const Particle &other)
        : _mass(other._mass), _size(other._size), _sizeToMassRatio(other._sizeToMassRatio)
{
    qDebug() << "Particle::Particle(const Particle &other) constructor called on " << this;
    if (other.getForceType()->getForceTypeString() == "Repel")
    {
        _forceType = new RepelForceType;
        *_forceType = *other.getForceType();
    }
    if (other.getForceType()->getForceTypeString() == "Attract")
    {
        _forceType = new AttractForceType;
        *_forceType = *other.getForceType();
    }
    else
    {
        qDebug() << "Particle::Particle(const Particle &other) failed because the ForceTypeString could not be recognized. Check for typos and try again";
        exit(-2);
    }
    _position = new dp::Vector(*other.getVector("Position"));
    _velocity = new dp::Vector(*other.getVector("Velocity"));
    _acceleration = new dp::Vector(*other.getVector("Acceleration"));
    _netForce = new dp::Vector(*other.getVector("Net Force"));
}

Particle::Particle(double mass, double sizeToMassRatio)
            : _forceType(nullptr), _position(nullptr),
              _velocity(nullptr), _acceleration(nullptr),
              _netForce(nullptr)
{
    qDebug() << "Particle::Particle(double mass, double sizeToMassRatio) constructor called on " << this;
    setMass(mass);
    setSizeToMassRatio(sizeToMassRatio); //Also updates size
}


Particle::Particle(double mass, double sizeToMassRatio, AbstractForceType *forceType)
    : _position(nullptr), _velocity(nullptr),
      _acceleration(nullptr), _netForce(nullptr)
{
    qDebug() << "Particle::Particle(double mass, double sizeToMassRatio, AbstractForceType *forceType) constructor called on " << this;
    setMass(mass);
    setSizeToMassRatio(sizeToMassRatio); //Also updates size
    setForceType(forceType);
}

Particle::Particle(double mass, double sizeToMassRatio,
                   AbstractForceType *forceType,
                   dp::Vector *position, dp::Vector *velocity,
                   dp::Vector *acceleration, dp::Vector *netForce)
    : _forceType(forceType), _position(position),
      _velocity(velocity), _acceleration(acceleration),
      _netForce(netForce)
{
    /*qDebug() << "Particle::Particle(double mass, double sizeToMassRatio, " <<
                "AbstractForceType *forceType, " <<
                "dp::Vector *position, dp::Vector *velocity, " <<
                "dp::Vector *acceleration, dp::Vector *netForce) constructor called on " << this;*/
    setMass(mass);
    setSizeToMassRatio(sizeToMassRatio); //Also updates size
    _forceType->setParent(this);
    _position->setParent(this);
    _velocity->setParent(this);
    _acceleration->setParent(this);
    _netForce->setParent(this);
}



Particle::~Particle()
{
    qDebug() << "Particle::~Particle() destructor called on " << this;
    if (_forceType != nullptr)
        delete _forceType;
    if (_position != nullptr)
        delete _position;
    if (_velocity != nullptr)
        delete _velocity;
    if (_acceleration != nullptr)
        delete _acceleration;
    if (_netForce != nullptr)
        delete _netForce;
}

double Particle::getMass() const
{
    return _mass;
}



//Getters**********************************************************************************
dp::Vector *Particle::getVector(QString vType) const
{
    //Returns _position, _velocity, _acceleration or _netForce,
    //Depending on the value of vType

    if (vType == "Position")
        return _position;
    if (vType == "Velocity")
        return _velocity;
    if (vType == "Acceleration")
        return _acceleration;
    if (vType == "Net Force")
        return _netForce;
    else {
        QMessageBox::critical(nullptr, "Error", "Incorrect argument provided in dp::Vector *Particle::getVector(QString vType) const. Please enter 'Position', 'Velocity', 'Acceleration' or 'Net Force'."
                                                "Please specify correct value");
        exit(-1);
    }
}

AbstractForceType *Particle::getForceType() const
{
    return _forceType;
}
//Setters**********************************************************************************

void Particle::setMass(double mass)
{
    if (mass < 0)
    {
        QMessageBox::critical(nullptr, "Error", "The mass cannot be less than 0. Please enter a positive number."
                                                "Value has been set to 1");
        _mass = 1;
    }
    else {
        _mass = mass;
    }
}

void Particle::setSize(double size)
{
    if (size < 0)
    {
        QMessageBox::critical(nullptr, "Error", "The size cannot be less than 0. Please enter a positive number."
                                                "Value has been set to 1");
        _size = 1;
    }
    else {
        _size = size;
    }
}

void Particle::setSizeToMassRatio(double sizeToMassRatio)
{
    if (sizeToMassRatio < 0)
    {
        QMessageBox::critical(nullptr, "Error", "The mass To Size Ratio cannot be less than 0. Please enter a positive number."
                                                "Value has been set to 1");
        _sizeToMassRatio = 1;
    }
    else {
        _sizeToMassRatio = sizeToMassRatio;
    }
    calcSize(); //Update the size according to the new ratio
}

void Particle::setForceType(AbstractForceType *forceType)
{
    _forceType = forceType;
}



void Particle::setVector(QString vType, dp::Vector *vector)
{
    if (vType == "Position")
        _position = vector;
    if (vType == "Velocity")
        _velocity = vector;
    if (vType == "Acceleration")
        _acceleration = vector;
    if (vType == "Net Force")
        _netForce = vector;
    else {
        QMessageBox::critical(nullptr, "Error", "Incorrect argument provided in Particle::setVector. Please enter 'Position', 'Velocity', 'Acceleration' or 'Net Force'.");
        exit(-1);
    }
}

void Particle::updateVector(QString vType, double x, double y)
{
    if (vType == "Position")
    {
        _position->setX(x);
        _position->setY(y);
    }
    if (vType == "Velocity")
    {
        _velocity->setX(x);
        _velocity->setY(y);
    }
    if (vType == "Acceleration")
    {
        _acceleration->setX(x);
        _acceleration->setY(y);
    }
    if (vType == "Net Force")
    {
        _netForce->setX(x);
        _netForce->setY(y);
    }
    else {
        QMessageBox::critical(nullptr, "Error", "Incorrect argument provided in Particle::updateVector. Please enter 'Position', 'Velocity', 'Acceleration' or 'Net Force'.");
        exit(-1);
    }
}

//Overloaded operators*********************************************************************
Particle &Particle::operator=(const Particle &other)
{
    if (this == &other)
        return *this;
    _mass = other._mass;
    _size = other._size;
    _sizeToMassRatio = other._sizeToMassRatio;
    if (other.getForceType()->getForceTypeString() == "Repel")
    {
        _forceType = new RepelForceType;
        *_forceType = *other.getForceType();
    }
    if (other.getForceType()->getForceTypeString() == "Attract")
    {
        _forceType = new AttractForceType;
        *_forceType = *other.getForceType();
    }
    else
    {
        qDebug() << "Particle &Particle::operator=(const Particle &other) failed because the ForceTypeString could not be recognized. Check for typos and try again";
        exit(-2);
    }
    _position = new dp::Vector(*other.getVector("Position"));
    _velocity = new dp::Vector(*other.getVector("Velocity"));
    _acceleration = new dp::Vector(*other.getVector("Acceleration"));
    _netForce = new dp::Vector(*other.getVector("Net Force"));
    return *this;

}

QDebug operator<<(QDebug d, const Particle &p)
{
    d << "Particle object:" << endl;
    d << "mass: " << p._mass << endl;
    d << "size: " << p._size << endl;
    d << "sizeToMassRatio: " << p._sizeToMassRatio << endl;
    d << "ForceType: " << *(p._forceType) << endl;
    d << "Position: " << *(p._position) << endl;
    d << "Velocity: " << *(p._velocity) << endl;
    d << "Acceleration: " << *(p._acceleration) << endl;
    d << "Net force: " << *(p._netForce) << endl;
    return d;
}

//Member functions*************************************************************************
dp::Vector Particle::calcNetForce()
{

}

dp::Vector Particle::calcAcceleration()
{

}



void Particle::calcSize()
{
    _size = _mass * _sizeToMassRatio;
}
