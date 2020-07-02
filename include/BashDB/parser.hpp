#ifndef PARSER_H
#define PARSER_H

namespace Parser {

    // Parses the input to ensure
    // necessary flags per subcommand
    // are given. Performs additional
    // safety checks.
    int parseInput(char *argv);

}

#endif
