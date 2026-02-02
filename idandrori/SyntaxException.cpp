#include "SyntaxException.h"

const char *SyntaxException::what(void) const noexcept
{
  return "SyntaxError: invalid syntax";
}
