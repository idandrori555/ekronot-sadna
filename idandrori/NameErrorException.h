#pragma once

#include "InterpreterException.h"
#include <string>

class NameErrorException : public InterpreterException
{
public:
  const char *what(void) const noexcept override;

private:
  std::string _name;
};
