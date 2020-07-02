#include <CLI11/CLI11.hpp>
#include <iostream>
#include <BashDB/parser.hpp>

namespace Parser {

  int parseInput(CLI::App *app, std::string key, std::string value) {
      if (verifyCommand(app, "get")) {
          std::cout << "Run Getter" << std::endl;
      } else if (verifyCommand(app, "put")) {
          std::cout << "Run Setter" << std::endl;
      } else if (verifyCommand(app, "safeput")) {
          std::cout << "Run Safe Setter" << std::endl;
      }
      return 0;
  }

  bool verifyCommand(CLI::App *app, std::string key){
      if ((*app).got_subcommand(key)) {
          return true;
      }
      return false;
  }
}
