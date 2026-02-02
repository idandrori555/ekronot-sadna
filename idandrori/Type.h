#pragma once

#include <string>

class Type
{
public:
  Type(void) = default;
  virtual ~Type(void) = default;

  bool getIsTemp(void) const;
  void setIsTemp(bool isTemp);

  virtual bool isPrintable(void) const = 0;
  virtual std::string toString(void) const = 0;

private:
  bool _isTemp{false};
};
