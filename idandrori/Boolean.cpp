#include "Boolean.h"

constexpr const char *TRUE_STR = "True";
constexpr const char *FALSE_STR = "False";

Boolean::Boolean(bool value) : _value(value)
{
}

bool Boolean::isPrintable(void) const
{
  return true;
}

std::string Boolean::toString(void) const
{
  return _value ? TRUE_STR : FALSE_STR;
};
