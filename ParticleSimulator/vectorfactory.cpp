#include "vectorfactory.h"

VectorFactory::VectorFactory() : _vectorsCreatedCount(0)
{
    qDebug() << "VectorFactory::VectorFactory() constructor called on " << this;
}

VectorFactory::~VectorFactory()
{
    qDebug() << "VectorFactory::~VectorFactory() destructor called on " << this;
}

dp::Vector *VectorFactory::newVector(double x, double y, Particle *parent)
{
    return new dp::Vector(x, y, parent);
}
