#include <iostream>
#include <string>
#include <BashDB/parser.hpp>

using namespace std;

namespace Parser {

  int parseInput(int argc, char *argv[]) {
    if (argc < 2) {
      show_usage();
      return 0;
    }
    // Convert first argument to action & dispatch corresponding action
    string res(argv[1]);

    // TODO: Parse options -> Dispatch action

    if(res == "get"){
       cout << "getExcellent!" << endl;
    } else if(res == "set"){
       cout << "setYou passed" << endl;
    } else if(res == "safeset"){
       cout << "safeBetter try again" << endl;
    } else {
      cout << "'" << res << "'" << " Not Found" << endl;
      show_usage();
      return 1;
    }
    return 0;
  }

  // Help menu
  static void show_usage() {
    std::cerr << "Usage:\n bashDB [ACTION] [OPTIONS]...\n"
      << "Actions:\n"
      << "\tget\t\tShow this help message\n"
      << "\tset\t\tShow this help message\n"
      << "\tsafeset\t\tShow this help message\n"
      << "Options:\n"
      << "\t-h,--help\t\tShow this help message\n"
      << "\t-k,--key\t\tShow this help message\n"
      << "\t-v,--value DESTINATION\tSpecify the destination path"
      << std::endl;
  }

}
