#ifndef PARSER_H
#define PARSER_H

#include <CLI11/CLI11.hpp>
#include <iostream>

namespace Parser {

    // Parses the input to ensure
    // necessary flags per subcommand
    // are given. Performs additional
    // safety checks.
    int parseInput(CLI::App *app, std::string key, std::string value);

    bool verifyCommand(CLI::App *app, std::string key);

}

#endif
