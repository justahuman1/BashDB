#include <CLI11/CLI11.hpp>
#include <BashDB/parser.hpp>


int main(int argc, char** argv) {
    CLI::App app{"BashDB - A key value store for bash scripts"};

    std::string key;
    std::string value;
    /* app.add_option("put", key, "Put a value in the corresponding key (will overwrite)", false); */

    // Subcommands
    app.add_subcommand("get", "Put a value in the corresponding key (will overwrite)");
    app.add_subcommand("put", "Put a value in the corresponding key (will overwrite)");
    app.add_subcommand("safeput", "Put a value in the corresponding key if not exists (does not overwrite)");

   // Flags
    app.add_option("-k,--key", key, "The key to use for the corresponding subcommand", false);
    app.add_option("-v,--value", value, "The value to use for the corresponding subcommand", false);

    CLI11_PARSE(app, argc, argv);
    Parser::parseInput(*argv);
    return 0;
}
