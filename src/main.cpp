#include <iostream>
#include <CLI11/CLI11.hpp>

int main(int argc, char** argv) {
    CLI::App app{"BashDB - A key value store for bash scripts"};

    std::string key;
    app.add_option("-p,--put", key, "Put a value in the corresponding key (will overwrite)", false);

    CLI11_PARSE(app, argc, argv);
    return 0;
}

int bashDB() {
    std::cout << "Welcome to bashDB" << std::endl;
    return 0;
}
