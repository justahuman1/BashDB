#include <cstdio>
#include <iostream>
#include <string>
#include <BashDB/parser.hpp>

namespace Parser {

  int parseInput(int argc, char *argv[]) {
    if (argc < 2) {
      show_usage();
      return 0;
    }
    // Convert first argument to action & dispatch corresponding action
    std::string res(argv[1]);

    if(res == "--help" || res == "-h"){
      show_usage();
      return 0;
    }
    // TODO: Parse options -> Dispatch action
    struct Flags flags;
    // Gate to track if the parsed arg was given a flag
    bool argGate = true;
    for (int i = 2; i < argc; i++) {
      std::string arg(argv[i]);
      if (arg[0] != '-' && argGate) {
        if(flags.key.empty()){
          flags.key = arg;
        } else if(flags.value.empty())  {
          flags.value = arg;
        } else {
          std::cout << "Unrecognized argument: " << arg
            << std::endl;
          return 1;
        }
      }
      if(arg == "-k" || arg == "--key"){
        flags.key = argv[i+1];
        argGate = false;
      } else if(arg == "-v" || arg == "--value"){
        flags.value = argv[i+1];
        argGate = false;
      } else {
        // Falls here after arg with flag was already
        // parsed, resetting the gate for future args
        argGate = true;
      }
    }
    if(res == "get"){
      handleGet();
    } else if(res == "set"){
      handleSet(argv, &flags);
    } else if(res == "safeset"){
      std::cout << "safeBetter try again" << std::endl;
    } else {
      std::cout << "'" << res << "'" << " Not Found" << std::endl;
      show_usage();
      return 1;
    }
    return 0;
  }

  // Help menu
  static void show_usage() {
    // Split help menu when CLI grows bigger
    std::cerr << "Usage:\n bashDB [ACTION] [OPTIONS]...\n"
      << "Actions:\n"
      << "\tget [k]\t\t\tGet the corresponding value for [key]\n"
      << "\tset [k] [v]\t\tSet the corresponding [value] for [key] (will overwrite)\n"
      << "\tsafeset [k] [v]\t\tSet the corresponding [value] for [key] if the key does not already exist (prevents overwriting)\n"
      << "Options:\n"
      << "\t-h,--help\t\tShow this help message\n"
      << "\t-k,--key\t\tThe key utilized for the [action]. Required for [get], [set], [safeset]\n"
      << "\t-v,--value\t\tThe value to assign for the [key]. Required for [set], [safeset]"
      << std::endl;
  }

  void handleGet(){
    std::cout << "handling Get" << std::endl;
    struct Flags flags;
  }
  void handleSet(char *argv[], Flags *flags){
      std::cout << flags->key << std::endl;
      if (flags->key.empty() || flags->value.empty()) {
        std::cout << "'set': Not enough arguments" << std::endl;
      }
  }
  void handleSafeSet(){

  }

}
