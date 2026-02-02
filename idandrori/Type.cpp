#include "Type.h"

Type::Type(void) : _isTemp(false)
{
}

void Type::setIsTemp(const bool isTemp)
{
  _isTemp = isTemp;
}

bool Type::getIsTemp(void) const
{
  return _isTemp;
}
