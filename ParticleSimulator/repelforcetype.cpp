#include "repelforcetype.h"

RepelForceType::RepelForceType()
{
    //qDebug() << "RepelForceType::RepelForceType() constructor called on " << this;
    setForceTypeString("Repel");
}

RepelForceType::RepelForceType(double constant)
{
    qDebug() << "RepelForceType::RepelForceType(double constant) called on " << this;
    setForceTypeString("Repel");
    addForceParameter(constant);
}

RepelForceType::RepelForceType(const RepelForceType &other)
{
    qDebug() << "RepelForceType::RepelForceType(const RepelForceType &other) called on " << this << ". Other is at " << &other;
    setForceTypeString("Repel");
}

RepelForceType::~RepelForceType()
{
    qDebug() << "RepelForceType::~RepelForceType() destructor called on " << this;
}

void RepelForceType::operator=(const RepelForceType &other)
{
    qDebug() << "void RepelForceType::operator=(const RepelForceType &other) called on " << this << ". Other is at " << &other;
    setForceTypeString("Repel");
    this->setParent(other.getParent());
    for (int i = 0; i < other.getParameterCount(); i++) {
        this->addForceParameter(other.getParameter(i));
    }
}

QDebug operator<<(QDebug d, const RepelForceType &r)
{
    d << "RepelForceType object: " << endl;
    d << "Parent: " << r.getParent() << endl;
    d << "Force type: " << r.getForceTypeString() << endl;
    d << "Parameter count: " << r.getParameterCount() << endl;
    for (int i = 0; i < r.getParameterCount(); i++) {
        d << "Parameter[" << i << "]: " << r.getParameter(i) << endl;
    }
    return d;
}


dp::Vector RepelForceType::calcForce(const Particle *p1, const Particle *p2)
{
    //NB: for attract force delta is p2 - p1. For repel force delta is p1 - p2
    //qDebug() << "dp::Vector RepelForceType::calcForce(const Particle *p1, const Particle *p2) with p1 at " << p1 <<" and p2 at" << p2;
    dp::Vector position, delta, force;
    double distance;
    double forceMagnitude;
    double scaleFactor;
    position = *p1->getVector("Position"); //Get the location of the particle
    //qDebug() << "Position: " << position;
    delta = position.calcDeltaVector(p2->getVector("Position")); //Get the vector between the two particles
    //qDebug() << "Delta vector: " << delta;
    distance = position.calcDistance(*p2->getVector("Position")); //Calculate the distance between the two particles
    //qDebug() << "Distance:" << distance;
    forceMagnitude = calcForceMagnitude(p1, p2); //Calculate the magnitude of the force acting on p1
    //qDebug() << "Force magnitude:" << forceMagnitude;
    scaleFactor = forceMagnitude / distance; //Calculate the value of the scaling vector k (F = k.D)
    //qDebug() << "Scale factor: " << scaleFactor;
    force = delta.scalarMultiply(scaleFactor);
    //qDebug() << "Force vector: " << force;
    //qDebug() << "***End of RepelForceType::calcForce " << endl;
    return force;
}

double RepelForceType::calcForceMagnitude(const Particle *p1, const Particle *p2)
{
    //qDebug() << "***double RepelForceType::calcForceMagnitude(const Particle *p1, const Particle *p2) with p1 at " << p1 <<" and p2 at" << p2;
    dp::Vector positionP1, delta, positionP2;
    double distance = 0;
    double forceMagnitude = 0;
    positionP1 = *p1->getVector("Position"); //Get the location of the particle
    //qDebug() << "position P1:" << positionP1;
    //qDebug() << "delta before:" << delta;
    positionP2 =  *p2->getVector("Position");
    //qDebug() << "position P2:" << positionP2;
    delta = positionP1.calcDeltaVector(p2->getVector("Position")); //Get the vector between the two particles
    //qDebug() << "Delta: " << delta;
    distance = positionP1.calcDistance(*p2->getVector("Position")); //Calculate the distance between the two particles
    //qDebug() << "Distance:" << distance;
    //qDebug() << "Parameter 0:" << this->getParameter(0);
    //qDebug() << "Parameter 1:" << this->getParameter(1);
    //qDebug() << "Mass 1:" << p1->getMass();
    //qDebug() << "Mass 2:" << p2->getMass();
    //qDebug() << "Repel force = Param0 * (m1 + m2) / (Param1 * distance + m1 +m2)";
    forceMagnitude = this->getParameter(0) * (p1->getMass() + p2->getMass()) / (this->getParameter(1) * distance + p1->getMass() + p2->getMass()); //Calculate the magnitude of the force acting on p1
    //qDebug() << "Force magnitude:" << forceMagnitude;
    //qDebug() << "***End of RepelForceType::calcForceMagnitude " << endl;
    return  forceMagnitude;
}
