#pragma once
#include "Helper.h"
#include "InterpreterException.h"
#include "Type.h"
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

class Parser
{
public:
  static Type *parseString(const std::string &str);
  static Type *getType(const std::string &str);

private:
};
