#include "Parser.h"
#include "Boolean.h"
#include "Helper.h"
#include "IndentationException.h"
#include "Integer.h"
#include "String.h"
#include "SyntaxException.h"
#include "Void.h"
#include "const.h"

Type *Parser::parseString(std::string &str)
{
  if (str.length() <= 0)
    return nullptr;

  Helper::trim(str);

  if (str.at(0) == NEW_LINE || str.at(0) == SPACE || str.at(0) == TAB)
    throw IndentationException();

  // Trim Ending Spaces
  Helper::rtrim(str);

  // First check if it's a variable lookup
  Type *type = getVariableValue(str);
  if (type != nullptr)
  {
    return type;
  }

  // Then check if it's a type literal
  type = getType(str);
  if (type != nullptr)
  {
    return type;
  }

  // Then try assignment
  if (makeAssignment(str))
  {
    // Return a temporary Void for successful assignment
    Type *voidType = new Void();
    voidType->setIsTemp(true);
    return voidType;
  }

  // Operation doesnt exist
  throw SyntaxException();
}

Type *Parser::getType(const std::string &str) noexcept
{
  if (str.length() <= 0)
    return nullptr;

  // Check for string first (since strings can look like integers or booleans)
  if (Helper::isString(str))
  {
    Type *type = new String(str);
    type->setIsTemp(true);
    return type;
  }

  // Check for boolean
  if (Helper::isBoolean(str))
  {
    Type *type = new Boolean(str == TRUE_STR);
    type->setIsTemp(true);
    return type;
  }

  // Check for integer
  if (Helper::isInteger(str))
  {
    Type *type = new Integer(std::stoi(str));
    type->setIsTemp(true);
    return type;
  }

  return nullptr;
}

bool Parser::isLegalVarName(const std::string &str)
{
  if (Helper::isDigit(str.at(0)))
    return false;

  for (char c : str)
  {
    if (c != UNDERSCORE && !Helper::isLetter(c) && !Helper::isDigit(c))
      return false;
  }

  return true;
}

bool Parser::makeAssignment(const std::string &str)
{
  if (str.length() <= 0)
    return false;

  auto eqPos = str.find(EQUAL_SIGN);

  if (eqPos == std::string::npos)
    return false;

  std::string varName = str.substr(0, eqPos);
  Helper::rtrim(varName);

  if (!isLegalVarName(varName))
    throw SyntaxException();

  std::string varValue = str.substr(eqPos + 1);
  Helper::trim(varValue);

  // Check if the value is a variable
  Type *type = getVariableValue(varValue);
  if (type != nullptr)
  {
    // Assign the variable to the value of the other varaible (shallow copy for now)
    _variables[varName] = type;
    return true;
  }

  type = getType(varValue);
  if (nullptr == type)
    throw SyntaxException();

  _variables[varName] = type;
  return true;
}

Type *Parser::getVariableValue(const std::string &str)
{
  // check str in _variables
  if (_variables.find(str) == _variables.end())
  {
    return nullptr;
  }

  return _variables.at(str);
}

void Parser::freeMemory(void)
{
  for (auto &[name, value] : Parser::_variables)
  {
    if (nullptr != value)
    {
      delete value;
    }
  }
}
