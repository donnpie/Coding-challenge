#include "abstractforcetype.h"

//Contructors and destructors**************************************************************
AbstractForceType::AbstractForceType() : _forceType(""), _parent(nullptr)
{
    //qDebug() << "AbstractForceType::AbstractForceType() called on " << this;
}

AbstractForceType::AbstractForceType(const AbstractForceType &other)
{
    qDebug() << "AbstractForceType::AbstractForceType(const AbstractForceType &other) called on " << this << ". Other is at " << &other;
    this->_parent = other._parent;
    this->_forceType = other._forceType;
    this->_forceParameters = other._forceParameters;
}

AbstractForceType::~AbstractForceType()
{
    qDebug() << "AbstractForceType::~AbstractForceType() destructor called on " << this;
}

//Getters**********************************************************************************
double AbstractForceType::getParameter(int position) const
{
    return _forceParameters[position];
}

int AbstractForceType::getParameterCount() const
{
    return _forceParameters.size();
}

QString AbstractForceType::getForceTypeString() const
{
    return _forceType;
}

Particle *AbstractForceType::getParent() const
{
    return _parent;
}

//Setters**********************************************************************************
void AbstractForceType::setParameter(int position, double value)
{
    _forceParameters[position] = value;
}

void AbstractForceType::setParent(Particle *parent)
{
    _parent = parent;
}

void AbstractForceType::setForceTypeString(QString fType)
{
    _forceType = fType;
}

//Overloaded operators*********************************************************************
AbstractForceType &AbstractForceType::operator=(const AbstractForceType &other)
{
    qDebug() << "AbstractForceType &AbstractForceType::operator=(const AbstractForceType &other) called on " << this << ". Other is at " << &other;
    if (this == &other)
        return *this;
    this->_parent = other._parent;
    this->_forceType = other._forceType;
    this->_forceParameters = other._forceParameters;
    return *this;
}

QDebug operator<<(QDebug d, const AbstractForceType &a)
{
    d << "AbstractForceType object: " << endl;
    d << "Parent: " << a._parent << endl;
    d << "Force type: " << a._forceType << endl;
    d << "Parameter count: " << a.getParameterCount() << endl;
    for (int i = 0; i < a.getParameterCount(); i++) {
        d << "Parameter[" << i << "]: " << a.getParameter(i) << endl;
    }
    return d;
}



//Member functions*************************************************************************
void AbstractForceType::addForceParameter(double value)
{
    _forceParameters.push_back(value);
}
