#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <cstdlib> //srand, rand
#include <ctime> //time
#include <QVector>
#include <QString>
#include <QObject>
#include <QMessageBox>
#include "forcetypefactory.h"
#include "vector.h"
#include "vectorfactory.h"
#include "particle.h"
#include "particlefactory.h"



//class Particle;
//class ParticleFactory;
//class ForceTypeFactory;
//class VectorFactory;

class Controller : public QObject
{
    Q_OBJECT
public:
//Contructors and destructors**************************************************************
    Controller();                                                                                           //Test OK
    Controller(int particleCount);                                                                          //Test OK
    virtual ~Controller();
//Getters and setters**********************************************************************
    void setParticleCount(int pCount);                                                                      //Test OK
    void setParticleFactory(ParticleFactory *pf); //Set a pointer to the Particle Factory                   //Must first complete particleFactory before testing this
    int getParticleCount() const;               //Returns the number of particles in the system             //Test OK
    QVector<Particle *> *getParticleList();     //Returns a pointer to the particle list                    //
    Particle *getParticle(int index);           //Returns the Particle and index of _particleList           //

//Overloaded operators*********************************************************************
    friend QDebug operator<<(QDebug d, const Controller &c);                                                //Test OK

//Signals and Slots************************************************************************
signals:
    void positionsUpdated(); //Emitted as soon as the loop has updated all positions

//Member functions*************************************************************************
public:
    void makeParticles(int n); //Create n new particles. Pass the pointers to _particleList                 //
                          //Delegates to ParticleFactory::makeParticle()
    void makeParticle();   //Creates a single new particle and adds it to _particleList                     //Must first complete particleFactory before testing this
    void makeParticle(double mass, double massToSizeRatio,
                      double pos_x, double pos_y,
                      QString forceType, double constant);
    void loop(int n); //Handles the animation
    void printParticles();

private:
//Data members*****************************************************************************
    QVector<Particle *> _particleList; //A pointer to a list containing
                                       //pointers to the particle objects
    ParticleFactory *_particleFactory;
    VectorFactory *_vectorFactory;
    ForceTypeFactory *_ftFactory;
    int _particleCount;

    double _aftConstant1 = 0.005;
    double _aftConstant2 = 50;
    double _rftConstant1 = 51;
    double _rftConstant2 = 1;
    double _mass1 = 1;
    double _mass2 = 1;
    QString _forceType = "Attract";
    Particle *_pPtr; //Used in Controller(int particleCount)
    Particle *_pPtr1; //Used in Controller() -  to be deleted later
    Particle *_pPtr2; //Used in Controller() -  to be deleted later



};



#endif // CONTROLLER_H



//Pre-conditions:
//Post-conditions:
