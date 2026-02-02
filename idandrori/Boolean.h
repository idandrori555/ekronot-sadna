#pragma once

#include "Type.h"

class Boolean : public Type
{
public:
  Boolean(bool value);
  ~Boolean(void) = default;

  bool isPrintable(void) const override;
  std::string toString(void) const override;

private:
  bool _value;
};
