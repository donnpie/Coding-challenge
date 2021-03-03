#ifndef PARTICLEFACTORY_H
#define PARTICLEFACTORY_H
#include "particle.h"

class ParticleFactory
{
public:
//Contructors and destructors**************************************************************
    ParticleFactory();
    ~ParticleFactory();

//Getters and setters**********************************************************************

//Overloaded operators*********************************************************************
//Member functions*************************************************************************
    Particle *newParticle();   //Creates a particle on the heap and returns
                                //a pointer to the Particle object
    Particle *newParticle(double mass, AbstractForceType *ft);
    Particle *newParticle(double mass, double massToSizeRatio);
    Particle *newParticle(double mass, double massToSizeRatio,
                          AbstractForceType *ft, dp::Vector *position,
                          dp::Vector *velocity, dp::Vector *acceleration,
                          dp::Vector *netForce);
//Data members*****************************************************************************
private:
    int _particlesCreatedCount;


};

#endif // PARTICLEFACTORY_H


//Getters**********************************************************************************
//Setters**********************************************************************************





//Pre-conditions:
//Post-conditions:
