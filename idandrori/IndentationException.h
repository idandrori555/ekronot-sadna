#pragma once
#include "InterpreterException.h"

class IndentationException : public InterpreterException
{
public:
  virtual const char *what(void) const noexcept override;
};
