#ifndef REPELFORCETYPE_H
#define REPELFORCETYPE_H
#include "abstractforcetype.h"
//#include "vector.h"  //Vector is already included in abstractforcetype.h
#include "particle.h" //Class Particle is forward declared in abstractforcetype.h

class RepelForceType : public AbstractForceType
{
public:
//Contructors and destructors**************************************************************
    RepelForceType();
    RepelForceType(double constant);
    RepelForceType(const RepelForceType &other);
    ~RepelForceType();

//Getters and setters**********************************************************************


//Overloaded operators*********************************************************************
    friend QDebug operator<<(QDebug d, const RepelForceType &r);
    void operator=(const RepelForceType &other);

//Member functions*************************************************************************
    dp::Vector calcForce(const Particle *p1, const Particle *p2);
                    //calculates the force exerted on p1 as a results of the
                    //presence of p2. The order of the parameters p1 and p2 matters
                    //Implements the calculation of a repulsive force
    double calcForceMagnitude(const Particle *p1, const Particle *p2);

//Data members*****************************************************************************




};



#endif // REPELFORCETYPE_H








//Pre-conditions:
//Post-conditions:
