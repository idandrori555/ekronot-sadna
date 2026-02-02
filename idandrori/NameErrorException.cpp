#include "NameErrorException.h"

const char *NameErrorException::what(void) const noexcept
{
  return "NameError: name is not defined";
}
