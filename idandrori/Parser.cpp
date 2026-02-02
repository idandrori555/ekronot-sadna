#include "Parser.h"
#include "IndentationException.h"
#include <iostream>

constexpr const char NEW_LINE = '\n';
constexpr const char SPACE = ' ';
constexpr const char TAB = '\t';

Type *Parser::parseString(const std::string &str)
{
  if (str.length() <= 0)
    return nullptr;

  if (str.at(0) == NEW_LINE || str.at(0) == SPACE || str.at(0) == TAB)
    throw IndentationException();

  std::cout << str << std::endl;

  return nullptr;
}
