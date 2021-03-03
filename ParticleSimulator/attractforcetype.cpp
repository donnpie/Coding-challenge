#include "attractforcetype.h"

//Contructors and destructors**************************************************************
AttractForceType::AttractForceType()
{
    //qDebug() << "AttractForceType::AttractForceType() called on " << this;
    setForceTypeString("Attract");
}

AttractForceType::AttractForceType(const AttractForceType &other)
{
    qDebug() << "AttractForceType::AttractForceType(const AttractForceType &other) called on " << this << ". Other is at " << &other;
    setForceTypeString("Attract");
}

AttractForceType::~AttractForceType()
{
    qDebug() << "AttractForceType::~AttractForceType() destructor called on " << this;
}
//Overloaded operators*********************************************************************
void AttractForceType::operator=(const AttractForceType &other)
{//Not tested!!!
    qDebug() << "void AttractForceType::operator=(const AttractForceType &other) called on " << this << ". Other is at " << &other;
    setForceTypeString("Attract");
    this->setParent(other.getParent());
    for (int i = 0; i < other.getParameterCount(); i++) {
        this->addForceParameter(other.getParameter(i));
    }
}

QDebug operator<<(QDebug d, const AttractForceType &a)
{
    d << "AttractForceType object: " << endl;
    d << "Parent: " << a.getParent() << endl;
    d << "Force type: " << a.getForceTypeString() << endl;
    d << "Parameter count: " << a.getParameterCount() << endl;
    for (int i = 0; i < a.getParameterCount(); i++) {
        d << "Parameter[" << i << "]: " << a.getParameter(i) << endl;
    }
    return d;
}
//Getters**********************************************************************************
//Setters**********************************************************************************
//Member functions*************************************************************************
dp::Vector AttractForceType::calcForce(const Particle *p1, const Particle *p2)
{
    //NB: for attract force delta is p2 - p1. For repel force delta is p1 - p2
    qDebug() << "***dp::Vector AttractForceType::calcForce(const Particle *p1, const Particle *p2) with p1 at " << p1 <<" and p2 at" << p2;
    dp::Vector position, delta, force;
    double distance;
    double forceMagnitude;
    double scaleFactor;
    position = *p1->getVector("Position"); //Get the location of the particle
    //qDebug() << "Position: " << position;
    delta = position.calcDeltaVector(p2->getVector("Position")); //Get the vector between the two particles
    delta.reverseDirection();
    qDebug() << "Delta vector: " << delta;
    distance = position.calcDistance(*p2->getVector("Position")); //Calculate the distance between the two particles
    qDebug() << "Distance: " << distance;
    forceMagnitude = calcForceMagnitude(p1, p2);
    qDebug() << "Force magnitude: " << forceMagnitude;
    scaleFactor = forceMagnitude / distance; //Calculate the value of the scaling vector k (F = k.D)
    qDebug() << "Scale factor: " << scaleFactor;
    force = delta.scalarMultiply(scaleFactor);
    qDebug() << "Force vector: " << force;
    qDebug() << "***End of AttractForceType::calcForce" << endl;
    return force;
}

double AttractForceType::calcForceMagnitude(const Particle *p1, const Particle *p2)
{
    //qDebug() << "***double AttractForceType::calcForceMagnitude(const Particle *p1, const Particle *p2) with p1 at " << p1 <<" and p2 at" << p2;
    dp::Vector position;
    double distance;
    double distanceThreshold = this->getParameter(1);
    double forceMagnitude;
    position = *p1->getVector("Position"); //Get the location of the particle
    distance = position.calcDistance(*p2->getVector("Position")); //Calculate the distance between the two particles
    //qDebug() << "Distance: " << distance;
    //qDebug() << "Distance threshold: " << distanceThreshold;
    if (distance < distanceThreshold)
        forceMagnitude = this->getParameter(0) * (p1->getMass() + p2->getMass()) * distance; //Calculate the magnitude of the force acting on p1
    else {
        forceMagnitude = this->getParameter(0) * (p1->getMass() + p2->getMass()) * distanceThreshold;
    }
    //qDebug() << "***End of AttractForceType::calcForceMagnitude" << endl;
    return forceMagnitude;
}
