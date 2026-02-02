#pragma once

#include "Sequence.h"
#include <string>

class String : public Sequence
{
public:
  String(const std::string &value);
  ~String(void) = default;

  bool isPrintable(void) const override;
  std::string toString(void) const override;

private:
  std::string _value;
};
