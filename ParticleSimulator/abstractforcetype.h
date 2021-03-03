#ifndef ABSTRACTFORCETYPE_H
#define ABSTRACTFORCETYPE_H
#include <QString>
#include <QVector>
#include "vector.h"
//#include "particle.h" //There is something wrong here. Get error when I include this header
                        //Used forward declaration to get around the problem

class Particle;

class AbstractForceType
{
public:
//Contructors and destructors**************************************************************
    AbstractForceType();
    AbstractForceType(const AbstractForceType &other);
    virtual ~AbstractForceType();

//Getters and setters**********************************************************************
    double getParameter(int position) const;
                    //Returns the parameter in position position
    int getParameterCount() const;
                    //Returns the number of parameters in _forceParameter vector
    QString getForceTypeString() const;
    Particle *getParent() const;
    void setParameter(int position, double value);
                    //Sets the parameter at position to value
                    //First position is 0
    void setParent(Particle *parent);
    void setForceTypeString(QString fType);


//Overloaded operators*********************************************************************
    AbstractForceType &operator=(const AbstractForceType &other);
    friend QDebug operator<<(QDebug d, const AbstractForceType & a);


//Member functions*************************************************************************
    void addForceParameter(double value);
                    //Appends a parameter to the end of the _forceParameter vector
    virtual dp::Vector calcForce(const Particle *p1, const Particle *p2) = 0;
                    //calculates the force exerted on p1 as a results of the
                    //presence of p2. The order of the parameters p1 and p2 matters
    virtual double calcForceMagnitude(const Particle *p1, const Particle *p2) = 0;
                    //calculates the magnitude of the force exerted on p1 as a results of the
                    //presence of p2. The order of the parameters p1 and p2 matters

//Data members*****************************************************************************
private:
    QString _forceType;
    QVector<double> _forceParameters;
    Particle *_parent; //Pointer that points back to the Particle object
                        //that owns this ForceType object

};

#endif // ABSTRACTFORCETYPE_H






//Pre-conditions:
//Post-conditions:
