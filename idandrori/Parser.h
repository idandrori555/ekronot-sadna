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
  static Type *parseString(std::string &str);
  static Type *getType(const std::string &str) noexcept;

  static void freeMemory(void);

private:
  static bool isLegalVarName(const std::string &str);
  static bool makeAssignment(const std::string &str);
  static Type *getVariableValue(const std::string &str);

public:
  inline static std::unordered_map<std::string, Type *> _variables{};
};
