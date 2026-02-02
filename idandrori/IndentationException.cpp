#include "IndentationException.h"

const char *IndentationException::what(void) const noexcept
{
  return "IndentationError: unexpected indent";
}
