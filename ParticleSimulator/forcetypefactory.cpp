#include "forcetypefactory.h"

ForceTypeFactory::ForceTypeFactory() : _forceTypesCreatedCount(0)
{
    //qDebug() << "ForceTypeFactory::ForceTypeFactory()  called on " << this;

}

ForceTypeFactory::ForceTypeFactory(const ForceTypeFactory &other) : _forceTypesCreatedCount(0)
{
    qDebug() << "ForceTypeFactory::ForceTypeFactory(const ForceTypeFactory &other)  called on " << this << ". Other is at " << &other;
}

ForceTypeFactory::~ForceTypeFactory()
{
    qDebug() << "ForceTypeFactory::~ForceTypeFactory() destructor called on " << this;
}

ForceTypeFactory &ForceTypeFactory::operator=(const ForceTypeFactory &other)
{
    qDebug() << "ForceTypeFactory &ForceTypeFactory::operator=(const ForceTypeFactory &other)  called on " << this << ". Other is at " << &other;
    _forceTypesCreatedCount = 0;
    return *this;
}

QDebug operator<<(QDebug d, const ForceTypeFactory &f)
{
    d << "ForceTypeFactory object:" << endl;
    d << "Number of ForceType objects created: " << f._forceTypesCreatedCount << endl;
    return d;
}

AbstractForceType *ForceTypeFactory::newForceType(QString forceType)
{
    AbstractForceType *f;
    if (forceType == "Repel")
    {
        f = new RepelForceType;
        f->setParent(nullptr);
        return f;
    }
    if (forceType == "Attract")
    {
        f = new AttractForceType;
        f->setParent(nullptr);
        return f;
    }
    else     {
        qDebug() << "AbstractForceType *ForceTypeFactory::newForceType(QString forceType) failed because the ForceTypeString could not be recognized. Check for typos and try again";
        exit(-3);
    }
}

AbstractForceType *ForceTypeFactory::newForceType(QString forceType, double constant)
{
    AbstractForceType *f;
    if (forceType == "Repel")
    {
        f = new RepelForceType;
        f->setParent(nullptr);
        f->addForceParameter(constant);
        return f;
    }
    if (forceType == "Attract")
    {
        f = new AttractForceType;
        f->setParent(nullptr);
        f->addForceParameter(constant); //When using this method for an attractForceType object, the second parameter has to be added manually
        return f;
    }
    else     {
        qDebug() << "AbstractForceType *ForceTypeFactory::newForceType(QString forceType) failed because the ForceTypeString could not be recognized. Check for typos and try again";
        exit(-3);
    }
}


AbstractForceType *ForceTypeFactory::newForceType(QString forceType, double constant, Particle *parent)
{
    AbstractForceType *f;
    if (forceType == "Repel")
    {
        f = new RepelForceType;
        f->setParent(parent);
        f->addForceParameter(constant);
        return f;
    }
    if (forceType == "Attract")
    {
        f = new AttractForceType;
        f->setParent(parent);
        f->addForceParameter(constant); //add parameter k
        f->addForceParameter(10); //add parameter distanceThreshold
        return f;
    }
    else return nullptr;
}

AbstractForceType *ForceTypeFactory::newForceType(QString forceType, double constant1, double constant2)
{
    AbstractForceType *f;
    if (forceType == "Repel")
    {
        f = new RepelForceType;
        f->setParent(nullptr);
        f->addForceParameter(constant1);
        f->addForceParameter(constant2);
        return f;
    }
    if (forceType == "Attract")
    {
        f = new AttractForceType;
        f->setParent(nullptr);
        f->addForceParameter(constant1); //add parameter k
        f->addForceParameter(constant2); //add parameter distanceThreshold
        return f;
    }
    else return nullptr;
}


AbstractForceType *ForceTypeFactory::newForceType(QString forceType, double constant1, double constant2, Particle *parent)
{
    AbstractForceType *f;
    if (forceType == "Repel")
    {
        f = new RepelForceType;
        f->setParent(parent);
        f->addForceParameter(constant1);
        f->addForceParameter(constant2);
        return f;
    }
    if (forceType == "Attract")
    {
        f = new AttractForceType;
        f->setParent(parent);
        f->addForceParameter(constant1); //add parameter k
        f->addForceParameter(constant2); //add parameter distanceThreshold
        return f;
    }
    else return nullptr;
}
