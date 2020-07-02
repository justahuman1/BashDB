#include <CLI11/CLI11.hpp>
#include <BashDB/parser.hpp>


int main(int argc, char** argv) {
    CLI::App app{"BashDB - A key value store for bash scripts"};
    app.require_subcommand(1, 1);

    Parser::parseInput(&app);
    CLI11_PARSE(app, argc, argv);
    return 0;
}
