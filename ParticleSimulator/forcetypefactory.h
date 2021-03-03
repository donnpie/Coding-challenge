#ifndef FORCETYPEFACTORY_H
#define FORCETYPEFACTORY_H
#include <QString>
#include <QtDebug>
#include "abstractforcetype.h"
#include "repelforcetype.h"
#include "attractforcetype.h"

class ForceTypeFactory
{
public:
//Contructors and destructors**************************************************************
    ForceTypeFactory();
                    //Default constructor creates a repelForceType
    ForceTypeFactory(const ForceTypeFactory &other);
    ~ForceTypeFactory();


//Getters and setters**********************************************************************
//Getters**********************************************************************************
//Setters**********************************************************************************
//Overloaded operators*********************************************************************
    ForceTypeFactory &operator=(const ForceTypeFactory &other);
    friend QDebug operator<<(QDebug d, const ForceTypeFactory &f);
//Member functions*************************************************************************
    AbstractForceType *newForceType(QString forceType);  //Creates a forcetype on the heap and returns
                                        //a pointer to the ForceType object
                                        //QString forceType determines what type of particle is created
    AbstractForceType *newForceType(QString forceType, double constant);  //Creates a forcetype on the heap and returns
                                        //a pointer to the ForceType object
                                        //QString forceType determines what type of particle is created
                                        //When using this method for an attractForceType object, the second parameter has to be added manually
    AbstractForceType *newForceType(QString forceType, double constant, Particle *parent);  //Creates a forcetype on the heap and returns
                                        //a pointer to the ForceType object
                                        //QString forceType determines what type of particle is created
                                        //When using this method for an attractForceType object, the second parameter has to be added manually
    AbstractForceType *newForceType(QString forceType, double constant1, double constant2);
    AbstractForceType *newForceType(QString forceType, double constant1, double constant2, Particle *parent);
//Data members*****************************************************************************
private:
    int _forceTypesCreatedCount;
};

#endif // FORCETYPEFACTORY_H
