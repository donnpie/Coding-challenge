#ifndef PARTICLE_H
#define PARTICLE_H

#include <QString>
#include <QVector>
#include <QMessageBox>
#include <cstdlib>
#include "abstractforcetype.h"
//#include "attractforcetype.h"
//#include "repelforcetype.h"
//#include "forcetypefactory.h"
#include "vector.h"

class ForceTypeFactory;
class AbstractForceType;
class AttractForceType;
class RepelForceType;
//class Controller;

class Particle
{
public:
//Contructors and destructors**************************************************************
    Particle();                                                                                                 //Test?
    Particle(const Particle &other);
    Particle(double mass, double sizeToMassRatio);                                                              //
                    //Initialises _forceType to nullptr
    Particle(double mass, double sizeToMassRatio, AbstractForceType *forceType);                                //
    Particle(double mass, double sizeToMassRatio, AbstractForceType *forceType,
             dp::Vector *position, dp::Vector *velocity,
             dp::Vector *acceleration, dp::Vector *netForce);
    ~Particle();

//Getters and setters**********************************************************************
public:
    double getMass() const;
    dp::Vector *getVector(QString vType) const;
                    //Returns _position, _velocity, _acceleration or _netForce,
                    //Depending on the value of vType
    AbstractForceType *getForceType() const;
    void setMass(double mass);
    void setSize(double size);
    void setSizeToMassRatio(double sizeToMassRatio);    //also updates _size
    void setForceType(AbstractForceType *forceType);    //Point the forceType pointer to new location
    //void setNeighbourCount(const Controller *c);
                    //Determine how many particles there are in the controller object
                    //and then set _neighbourCount to that value minus 1
                    //Delegate to Controller::getParticleCount
    void setVector(QString vType, dp::Vector *vector);
    void updateVector(QString vType, double x, double y);
                    //Sets the x and y coordinates for the vector specified by vType

//Overloaded operators*********************************************************************
    friend QDebug operator<<(QDebug d, const Particle &p);
    Particle &operator=(const Particle &other);

//Member functions*************************************************************************
    dp::Vector calcNetForce();
                    //Calculates the netforce exerted on this particle by its neighbours
                    //and stores the result in _netForce
                    //Pre-conditions: _mass must be set to a non-negative value
                    //              setNeigbourCount and findNeighbours must be
                    //              run before running calcNetForce
    dp::Vector calcAcceleration();
                    //Calculates the acceleration of this particle
                    //and stores the result in _acceleration
                    //Pre-conditions: _mass must be set to a non-negative value
                    //              setNeigbourCount and findNeighbours
                    //              and calcNetForce must be
                    //              run before running calcAcceleration
    //void findNeighbours(const Controller *c);
                    //Use the particle list in controller
                    //to populate neighbour list
                    //Delegate to Controller::*getParticleList()
                    //Pre-conditions: _mass must be set to a non-negative value
                    //              setNeigbourCount must be
                    //              run before running findNeighbours
    void calcSize();//Calculates the size from massToSizeRatio and sets _size


//Data members*****************************************************************************
private:
    double _mass;
    double _size; //must convert this to int to use for pixels
                    //Considder making this read only. sie should not be set directly
                    //Should be calculated using masToSizeRatio
    double _sizeToMassRatio;
    int _neighbourCount; //considder deleting this. can be replaced by function
    QVector<Particle*> _neighbours;
    AbstractForceType *_forceType;
    dp::Vector *_position;
    dp::Vector *_velocity;
    dp::Vector *_acceleration;
    dp::Vector *_netForce;




};



#endif // PARTICLE_H

//Pre-conditions:
//Post-conditions:
