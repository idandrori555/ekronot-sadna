#include "Parser.h"
#include "Boolean.h"
#include "Helper.h"
#include "IndentationException.h"
#include "Integer.h"
#include "String.h"
#include "SyntaxException.h"
#include "Void.h"
#include "const.h"
#include <iostream>

Type *Parser::parseString(std::string &str)
{
  if (str.length() <= 0)
    return nullptr;

  if (str.at(0) == NEW_LINE || str.at(0) == SPACE || str.at(0) == TAB)
    throw IndentationException();

  // Trim Ending Spaces
  Helper::rtrim(str);
  Type *type = getType(str);

  if (nullptr == type)
  {
    throw SyntaxException();
  }

  return type;
}

Type *Parser::getType(const std::string &str)
{
  if (str.length() <= 0)
    return nullptr;

  Type *type{nullptr};

  if (Helper::isBoolean(str))
  {
    type = new Boolean(str == TRUE_STR);
    type->setIsTemp(true);
  }

  if (Helper::isInteger(str))
  {
    // TODO: handle negative numbers as well (-)
    type = new Integer(std::stoi(str));
    type->setIsTemp(true);
  }

  if (Helper::isString(str))
  {
    type = new String(str);
    type->setIsTemp(true);
  }

  return type;
}
