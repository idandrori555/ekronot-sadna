#pragma once

#include "Sequence.h"
#include <string>

class String : public Sequence
{
public:
  String(const std::string &val);
  virtual ~String() = default;

  virtual bool isPrintable() const override;
  virtual std::string toString() const override;

private:
  std::string _value;
};
