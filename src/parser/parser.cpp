#include <CLI11/CLI11.hpp>
#include <iostream>
#include <BashDB/parser.hpp>

namespace Parser {

  int parseInput(CLI::App *app) {

    std::string key;
    std::string value;

    // Subcommands
    auto getter = app->add_subcommand("get", "Put a value in the corresponding key (will overwrite)");
    auto setter = app->add_subcommand("set", "Get the value for the corresponding key");
    auto safesetter = app->add_subcommand("safeset", "Put a value in the corresponding key if not exists (does not overwrite)");

   // Flags
   getter->add_option("-k,--key", key, "The key to use for the corresponding subcommand", false);
   setter->add_option("-k,--key", key, "The key to use for the corresponding subcommand", false);
   setter->add_option("-v,--value", value, "The value to use for the corresponding subcommand", false);

    handleGet(getter);
    handleSet(getter);
    handleSafeSet(getter);
    return 0;
  }

  void handleGet(CLI::App *getter){
      getter->callback( [&](){
          std::cout << "Getter callback" << std::endl;
      });
  }
  void handleSet(CLI::App *setter){
      setter->callback( [&](){
          std::cout << "Getter callback" << std::endl;
      });
  }
  void handleSafeSet(CLI::App *safesetter){
      safesetter->callback( [&](){
          std::cout << "Getter callback" << std::endl;
      });
  }

}
