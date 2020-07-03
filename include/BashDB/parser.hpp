#ifndef PARSER_H
#define PARSER_H

#include <CLI/CLI11.hpp>
#include <iostream>

namespace Parser {

    // Parses the input to ensure
    // necessary flags per subcommand
    // are given. Performs additional
    // safety checks.
    int parseInput(CLI::App *app);

    // Subcommand handlers isolated for
    // per command logic to interact with
    // the BashDB daemon.
    void handleGet(CLI::App *getter);
    void handleSet(CLI::App *setter);
    void handleSafeSet(CLI::App *safesetter);

}

#endif
