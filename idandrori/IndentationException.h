#pragma once
#include "InterpreterException.h"

class IndentationException : public InterpreterException
{
  virtual const char *what(void) const noexcept;
};
