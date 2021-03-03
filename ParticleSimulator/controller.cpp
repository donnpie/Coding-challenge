#include "controller.h"
//#include "particlefactory.h"

Controller::Controller() : _particleCount(0)
{
    qDebug() << "Controller::Controller() constructor called";
    _forceType = "Attract";
    _pPtr1 = new Particle(_mass1, 1, _ftFactory->newForceType(_forceType, _aftConstant1),
                                   new dp::Vector(50, 50), new dp::Vector(0, 0),
                                   new dp::Vector(0, 0),new dp::Vector(0, 0) );
    _pPtr1->getForceType()->addForceParameter(_aftConstant2);

    _forceType = "Repel";
    _pPtr2 = new Particle(_mass2, 1, _ftFactory->newForceType(_forceType, _rftConstant1),
                                   new dp::Vector(-50, -50), new dp::Vector(0, 0),
                                   new dp::Vector(0, 0),new dp::Vector(0, 0) );
    //qDebug() << "pPrt1: " << *pPtr1 << "pPrt2: " << *pPtr2;
}

Controller::Controller(int particleCount) : _particleCount(particleCount)
{
    //qDebug() << "***Controller::Controller(int particleCount) constructor called on " << this;
    if (particleCount < 1)
    {
        QMessageBox::critical(nullptr, "Error", "The number of particles cannot be less than 1. Please enter a positive integer.");
        exit(-5);
    }
    else {
        srand(time(0)); //Seed the random number generator
        double x, y;
        int limit = 50;
        int quadrant;
        for (int i = 0; i < particleCount; i++)
        {
            //qDebug() << "Iteration: " << i;
            //create random starting postition
             quadrant = rand() % 4;
             //qDebug() <<"Quadrant: " << quadrant << endl;
            if (quadrant == 0)
            {
                //Somewhere in quadrant 0
                x = static_cast<double>(rand() % limit);
                y = static_cast<double>(rand() % limit);
            }
            else if (quadrant == 1)
            {
                //Somewhere in quadrant 1
                x = static_cast<double>(-rand() % limit);
                y = static_cast<double>(rand() % limit);
            }
            else if (quadrant == 2)
            {
                //Somewhere in quadrant 2
                x = static_cast<double>(-rand() % limit);
                y = static_cast<double>(-rand() % limit);
            }
            else if (quadrant == 3)
            {
                //Somewhere in quadrant 3
                x = static_cast<double>(rand() % limit);
                y = static_cast<double>(-rand() % limit);
            }
            else {
                qDebug() << "Quadrant does not have a valid value. Must be 0..3";
                exit(-4);
            }
            //Create forceType and new particle
            //if (rand() % 2 == 1)
            //if (true) //Override creation of repel particles
            if (false) //Override creation of attract particles
            {
                _forceType = "Attract";
                _pPtr = new Particle(_mass1, 1, _ftFactory->newForceType(_forceType, _aftConstant1, _aftConstant2),
                                               new dp::Vector(x, y), new dp::Vector(0, 0),
                                               new dp::Vector(0, 0),new dp::Vector(0, 0) );
                //qDebug() << _forceType << " particle was created at " << _pPtr;
            }
            else {
                //_forceType = "Repel";
                _pPtr = new Particle(_mass1, 1, _ftFactory->newForceType(_forceType, _rftConstant1, _rftConstant2),
                                               new dp::Vector(x, y), new dp::Vector(0, 0),
                                               new dp::Vector(0, 0),new dp::Vector(0, 0) );
                //qDebug() << _forceType << " particle was created at " << _pPtr;
            }

            //Add particle to particle list
            //qDebug() << "Before add particle";
            _particleList.append(_pPtr);
            //qDebug() << "After add particle";

            //print the result
            //qDebug() << *_pPtr;
        }
    }
    qDebug() << "Controller::Controller(int particleCount) complete" << endl;
}

Controller::~Controller()
{
    qDebug() << "Controller::~Controller() destructor called on " << this;
    //delete _particleList;
    for (int i = 0; i < _particleList.length(); i++)
    {
        qDebug() << "Deleting particle " << i << endl;
        delete _particleList[i];
    }
    delete _particleFactory;
    _particleFactory = nullptr;
    delete _vectorFactory;
    _vectorFactory = nullptr;
    delete _particleFactory;
    _particleFactory = nullptr;
    if (_pPtr != nullptr)
    {
        delete _pPtr;
        _pPtr = nullptr;
    }
    if (_pPtr1 != nullptr)
    {
        delete _pPtr1;
        _pPtr1 = nullptr;
    }
    if (_pPtr2 != nullptr)
    {
        delete _pPtr2;
        _pPtr2 = nullptr;
    }
}

void Controller::setParticleCount(int pCount)
{
    _particleCount = pCount;
}

void Controller::setParticleFactory(ParticleFactory *pf)
{
    _particleFactory = pf;
}

int Controller::getParticleCount() const
{
//    if (_particleList != nullptr)
//        return _particleList->size();
//    else
//        return 0;
}

QVector<Particle *> *Controller::getParticleList()
{
    return &_particleList;
}

Particle *Controller::getParticle(int index)
{
    if ((index < _particleList.count()) && (index >= 0))
    {
        return  _particleList.at(index);
    }
    else {
        QString max = QString::number(getParticleCount() - 1);
        QMessageBox::critical(nullptr, "Error: Particle *Controller::getParticle(int index)",
                              "The index provided is out of range. Please enter an integer between 0 and " +  max);

        return nullptr;
    }
}

void Controller::makeParticles(int n)
{
    for (int i = 0; i < n; i++)
    {
        //do something
    }
}



void Controller::makeParticle(double mass, double massToSizeRatio, double pos_x, double pos_y, QString forceType, double constant)
{
    Particle *particle = _particleFactory->newParticle(mass, massToSizeRatio);
    particle->calcSize();
    dp::Vector *vector = _vectorFactory->newVector(pos_x, pos_y, particle);
    particle->setVector("Position", vector);
    vector = _vectorFactory->newVector(0, 0, particle);
    particle->setVector("Velocity", vector);
    vector = _vectorFactory->newVector(0, 0, particle);
    particle->setVector("Acceleration", vector);
    vector = _vectorFactory->newVector(0, 0, particle);
    particle->setVector("Net force", vector);
    AbstractForceType *ft = _ftFactory->newForceType(forceType, constant, particle);
    particle->setForceType(ft);
}

//void Controller::positionsUpdated() {}

void Controller::loop(int n)
{
    qDebug() << "***void Controller::loop(int n) start" << endl;
    int particleCount = _particleList.count();
    dp::Vector *position = new dp::Vector[particleCount]; //one vector for each particle
    dp::Vector *velocity = new dp::Vector[particleCount];
    dp::Vector *acceleration = new dp::Vector[particleCount];
    dp::Vector *forceComponent = new dp::Vector[particleCount];

    for (int i = 0; i < n; i++)
    {
        //qDebug() << "***Iteration " << i << ":" << endl;

        //Calc force
        for (int j = 0; j < particleCount; j++)
        {
            _pPtr1 = _particleList[j];
            _pPtr1->getVector("Net Force")->reset(); //Reset x, y back to 0
            for (int k = 0; k < particleCount; k++)
            {

                if (j != k)
                {
                    qDebug() << "Calculating force component for particles " << j << " and " << k;
                    _pPtr2 = _particleList[k];
                    forceComponent[j] = _pPtr1->getForceType()->calcForce(_pPtr1, _pPtr2);
                    _pPtr1->getVector("Net Force")->addVector(forceComponent[j]);
                    qDebug() << "Force component: " << forceComponent[j];
                }
                //qDebug() << "pPtr1 net force: " << *_pPtr1->getVector("Net Force");
            }
            qDebug() << "Particle" << j << "net force: " << *_pPtr1->getVector("Net Force");
        }
        qDebug() << "***";

        //Calc acceleration
        for (int j = 0; j < particleCount; j++)
        {
            _pPtr1 = _particleList[j];
            if (i != 0)
            {
                //qDebug() << "Calculating force acceleration for particles " << j;
                acceleration[j] = *_pPtr1->getVector("Acceleration"); //make a copy
                *_pPtr1->getVector("Acceleration") = _pPtr1->getVector("Net Force")->scalarMultiply(1/_pPtr1->getMass());
                qDebug() << "Particle" << j << "acceleration: " << *_pPtr1->getVector("Acceleration");

            }
            else {
                //qDebug() << "Calculating force acceleration for particles " << j;
                *_pPtr1->getVector("Acceleration") = _pPtr1->getVector("Net Force")->scalarMultiply(1/_pPtr1->getMass());
                acceleration[j] = *_pPtr1->getVector("Acceleration");
                qDebug() << "Particle" << j << "acceleration: " << *_pPtr1->getVector("Acceleration");
            }
        }
        qDebug() << "***";

        //Calc velocity
        for (int j = 0; j < particleCount; j++)
        {
            _pPtr1 = _particleList[j];
            if (i != 0)
            {
                velocity[j] = *_pPtr1->getVector("Velocity"); //Make a copy of velocity
                *_pPtr1->getVector("Velocity") = *_pPtr1->getVector("Acceleration") + velocity[j]; //update velocity
                qDebug() << "Particle" << j << "velocity: " << *_pPtr1->getVector("Velocity");
            }
            else {
                velocity[j] = *_pPtr1->getVector("Velocity"); //Make a copy of velocity
                *_pPtr1->getVector("Velocity") = *_pPtr1->getVector("Acceleration") + velocity[j]; //update velocity
                qDebug() << "Particle" << j << "velocity: " << *_pPtr1->getVector("Velocity");
            }
        }
        qDebug() << "***";

        //Calc positions
        for (int j = 0; j < particleCount; j++)
        {
            _pPtr1 = _particleList[j];
            if (i != 0)
            {
                position[j] = *_pPtr1->getVector("Position"); //Make a copy of Position
                *_pPtr1->getVector("Position") = acceleration[j].scalarMultiply(0.5) + velocity[j] + position[j];
                qDebug() << "Particle" << j << "Position: " << *_pPtr1->getVector("Position");
            }
            else {
                position[j] = *_pPtr1->getVector("Position"); //Make a copy of Position
                *_pPtr1->getVector("Position") = acceleration[j].scalarMultiply(0.5) + velocity[j] + position[j];
                qDebug() << "Particle" << j << "Position: " << *_pPtr1->getVector("Position");
            }
        }
        //qDebug() << "***requested emit positionsUpdated()";
        //emit positionsUpdated();


        qDebug() << "***";

        //Print distances
        for (int j = 0; j < particleCount; j++)
        {
            _pPtr1 = _particleList[j];
            for (int k = j+1; k < particleCount; k++)
            {
                if (j != k)
                {
                    _pPtr2 = _particleList[k];
                    qDebug() << "Distance between " << j << " and " << k << ":" << _pPtr1->getVector("Position")->calcDistance(*_pPtr2->getVector("Position"));
                }
            }
        }

        qDebug() << "***************************************************************" << endl;
    }

    //delete temporary dynamic arrays
    delete [] position;
    delete [] velocity;
    delete [] acceleration;
    delete [] forceComponent;
    qDebug() << "***void Controller::loop(int n) end" << endl;
}

void Controller::printParticles()
{
    //qDebug() << "void Controller::printParticles() started" << endl;
    qDebug() << "Number of particles: " << _particleList.count() << endl;
    for (int i = 0; i < _particleList.count(); i++)
        qDebug() << "Particle " << i << *getParticle(i) << endl;
    //qDebug() << "void Controller::printParticles() ended" << endl;
}

QDebug operator<<(QDebug d, const Controller &c)
{
    d << "Controller count: " << c._particleCount;
    return d;
}
