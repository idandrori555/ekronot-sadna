#pragma once

#include <exception>

class InterpreterException : public std::exception
{
public:
  virtual const char *what(void) const noexcept = 0;
};
