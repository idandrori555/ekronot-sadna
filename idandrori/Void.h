#pragma once

#include "Type.h"

class Void : public Type
{
  Void(void) = default;
  ~Void(void) = default;

  virtual bool isPrintable(void) const override;
  virtual std::string toString(void) const override;
};
