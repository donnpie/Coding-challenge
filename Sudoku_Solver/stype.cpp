#include "stype.h"
#include <iostream>

sType::sType(int value, State state) : _value(value), _state(state)
{

}

void sType::print()
{
    std::cout << _value;
}

int sType::value() const
{
    if (_state != State::empty)
        return _value;
    else {
        return 0;
    }
}

void sType::setValue(int value)
{
    if ((value > 0) && (value < 10))
    {
        _value = value;
        setState(State::filled);
    }
}

void sType::setValueFixed(int value)
{
    if ((value > 0) && (value < 10))
    {
        _value = value;
        setState(State::fixed);
    }
}

bool sType::reset()
{
    if (_state != State::fixed)
    {
        _value = 0;
        _state = State::empty;
        return true;
    }
    else {
        return false;
    }
}

State sType::state() const
{
    return _state;
}

void sType::setState(const State &state)
{
    if (_state != State::fixed) //Can only set to fixed one time. Once the state is set to fixed, cannot change it again
        _state = state;
    else {
        return;
    }
}
