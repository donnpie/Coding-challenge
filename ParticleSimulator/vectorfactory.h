#ifndef VECTORFACTORY_H
#define VECTORFACTORY_H
#include "particle.h"


class VectorFactory
{
public:
//Contructors and destructors**************************************************************
    VectorFactory();
    ~VectorFactory();

//Getters and setters**********************************************************************

//Overloaded operators*********************************************************************

//Member functions*************************************************************************
    dp::Vector *newVector(double x, double y, Particle *parent);

//Data members*****************************************************************************
private:
    int _vectorsCreatedCount;
};

#endif // VECTORFACTORY_H
