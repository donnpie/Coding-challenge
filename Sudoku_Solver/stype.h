#ifndef STYPE_H
#define STYPE_H

enum State {empty, filled, fixed};

class sType
{
public:
    sType(int value = 0, State state = State::empty);
    void print();

    int value() const;
    void setValue(int value);
    void setValueFixed(int value);
    bool reset();
        //Returns true if value was succesfully reset
        //Returns false when trying to reset a fixed value

    State state() const;
    void setState(const State &state);



private:
    int _value;
    State _state;

};

#endif // STYPE_H
