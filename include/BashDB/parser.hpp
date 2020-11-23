#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>

namespace Parser {

// Flags used to group all given args per command
struct Flags {
  /* char type; */
  std::string key;
  std::string value;
};
// Parses the input to ensure necessary flags per subcommand
// are given. Performs additional safety checks.
int parseInput(int argc, char *argv[]);

// Help Menu
static void show_usage();

// Subcommand handlers isolated for per command
// logic to interact with the BashDB daemon.
void handleGet();
void handleSet(char *argv[], Flags *flags);
void handleSafeSet();

}  // namespace Parser

#endif
