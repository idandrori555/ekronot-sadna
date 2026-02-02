#pragma once

#include "Type.h"

class Integer : public Type
{
public:
  Integer(int value);
  ~Integer(void) = default;

  bool isPrintable(void) const override;
  std::string toString(void) const override;

private:
  int _value;
};
