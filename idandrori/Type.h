#pragma once

#include <string>

class Type
{

public:
  Type(void);
  virtual ~Type(void) = default;

  virtual void setIsTemp(const bool isTemp);
  virtual bool getIsTemp(void) const;

  virtual bool isPrintable(void) const = 0;
  virtual std::string toString(void) const = 0;

private:
  bool _isTemp;
};
