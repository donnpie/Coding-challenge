#ifndef VECTOR_H
#define VECTOR_H
#include <QDebug>
#include <cmath>

namespace  dp {
    class Vector;
    QDebug operator<<(QDebug d, const Vector &v);
}//namespace dp

class Particle;

class dp::Vector
{
public:
//Contructors and destructors**************************************************************
    Vector();
    Vector(double x, double y);
    Vector(double x, double y, Particle *parent);
    Vector(const Vector &other); //Copy constructor
    ~Vector();

//Getters and setters**********************************************************************
    double getX();
    double getY();
    Particle *getParent();

    void setX(double x);
    void setY(double y);
    void setParent(Particle *parent);

//Overloaded operators*********************************************************************
    friend QDebug operator<<(QDebug d, const Vector &v);

    //Should these rather be implemented as void functions?
    dp::Vector operator+(const dp::Vector &otherVector) const;                                  //Test OK
                        //Returns a reference to a Vector object that is the sum of
                        //this vector and otherVector
    void addVector(const dp::Vector &otherVector);                                              //Test OK
                        //Adds otherVector to this Vector
    void operator=(const dp::Vector &otherVector);                                              //Test OK
                        //Sets this vector equal to otherVector
    //dp::Vector operator=(dp::Vector &otherVector) const;                                              //?
                        //Sets this vector equal to otherVector
    friend QDebug dp::operator<<(QDebug d, const Vector &v);                                    //Test OK


//Member functions*************************************************************************
    dp::Vector calcDeltaVector(const dp::Vector *otherVector) const;                            //Test OK
                        //Returns a Vector object that is the
                        //difference between this vector and anotherVector
    double calcDistance(const dp::Vector &otherVector) const;                                   //Test OK
                        //Calculates the distance between two
                        //points on the cartesian plane. The points are represented by
                        //dp::Vector objects.
    void scalarMultiplyMe(double scalar);                                                         //Test OK
                        //multiplies this instance by a scalar
    dp::Vector scalarMultiply(double scalar) const;                                                         //?
                        //multiplies this instance by a scalar and returns an new object
    double calcLength();                                                                        //Test OK
                        //Calculates the lentgth of this Vector
    void reverseDirection();                                                                    //Test OK
                        //Reverses the direction of this vector
    void reset();
                        //resets the x and y coordinates to 0


//Data members*****************************************************************************
private:
    double  _x, _y; //x and y coordinates
    Particle *_parent; //Pointer to the parent object of this object

};




#endif // VECTOR_H










//Pre-conditions:
//Post-conditions:
