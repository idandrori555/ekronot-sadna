#include "InterpreterException.h"
#include "Parser.h"
#include "SyntaxException.h"
#include "Type.h"
#include "const.h"
#include <iostream>
#include <print>

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
      Type *type = Parser::parseString(input_string);

      if (type->isPrintable())
      {
        std::cout << type->toString() << std::endl;

        if (type->getIsTemp())
        {
          delete type;
        }
      }
    }
    catch (const InterpreterException &e)
    {
      std::cout << e.what() << std::endl;
    }
    catch (...)
    {
      std::cout << "Unknown error" << std::endl;
    }

    // get new command from user
    std::cout << ">>> ";
    std::getline(std::cin, input_string);
  }

  return 0;
}
