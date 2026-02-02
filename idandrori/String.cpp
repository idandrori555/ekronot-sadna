#include "String.h"

String::String(const std::string &value) : Sequence(), _value(value)
{
}

std::string String::toString(void) const
{
  return _value;
};
