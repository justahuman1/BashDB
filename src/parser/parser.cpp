#include <iostream>
#include <BashDB/parser.hpp>

namespace Parser {

  int parseInput(char *argv) {
      std::cout << "Welcome to bashDB" << std::endl;
      std::cout << *argv << std::endl;
      return 0;
  }
}
