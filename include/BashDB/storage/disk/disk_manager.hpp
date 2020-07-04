#pragma once

#include <string>
#include <iostream>
#include <fstream>

namespace Storage {

/**
 * The DiskManager will provide the allocation and deallocation of pages within bashDB. This component handles all the
 * internals of writing pages to and from disk.
 */
class DiskManager {
    public:
     explicit DiskManager(const std::string &db_file);

     void WriteData(const std::string key, const char *key_data);

    private:
     std::fstream db_io_;
     std::string file_name_;
}

}
