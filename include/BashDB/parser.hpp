#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>

namespace Parser {

  // Parses the input to ensure
  // necessary flags per subcommand
  // are given. Performs additional
  // safety checks.
  int parseInput(int argc, char *argv[]);

  // Help Menu
  static void show_usage();

  // Subcommand handlers isolated for
  // per command logic to interact with
  // the BashDB daemon.
  /* void handleGet(CLI::App *getter); */
  /* void handleSet(CLI::App *setter); */
  /* void handleSafeSet(CLI::App *safesetter); */

}

#endif
