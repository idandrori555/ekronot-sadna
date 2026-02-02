#pragma once

#include "Type.h"
#include <string>

class Sequence : public Type
{
public:
  Sequence() = default;
  virtual ~Sequence() = default;

  virtual bool isPrintable() const = 0;
  virtual std::string toString() const = 0;
};
