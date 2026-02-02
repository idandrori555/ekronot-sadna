#include "InterpreterException.h"
#include "Parser.h"
#include "Type.h"
#include <iostream>

constexpr const char *WELCOME = "Welcome to Magshimim Python Interperter version 1.0 by ";
constexpr const char *YOUR_NAME = "Idan Drori";

int main(int argc, char **argv)
{
  std::cout << WELCOME << YOUR_NAME << std::endl;

  std::string input_string;

  // get new command from user
  std::cout << ">>> ";
  std::getline(std::cin, input_string);

  while (input_string != "quit()")
  {
    try
    {
      Parser::parseString(input_string);
    }
    catch (const InterpreterException &e)
    {
      std::cout << e.what() << std::endl;
    }

    // get new command from user
    std::cout << ">>> ";
    std::getline(std::cin, input_string);
  }

  return 0;
}
