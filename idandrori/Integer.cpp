#include "Integer.h"
#include <string>

Integer::Integer(int value) : _value(value) {};

bool Integer::isPrintable(void) const
{
  return true;
}

std::string Integer::toString(void) const
{
  return std::to_string(_value);
};
