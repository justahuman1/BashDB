#include <CLI/CLI11.hpp>
#include <BashDB/parser.hpp>


int main(int argc, char** argv) {
    CLI::App app{"BashDB - A key value store for bash scripts"};
    app.require_subcommand(1, 1);

    Parser::parseInput(&app);
    app.set_help_all_flag("--help-all", "Expand all help");
    /* app.set_version_flag("--version", "Mews"); */
    CLI11_PARSE(app, argc, argv);
    return 0;
}
