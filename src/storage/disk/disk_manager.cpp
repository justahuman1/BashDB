#include <iostream>
#include <fstream>
#include <storage/disk/disk_manager.hpp>

namespace Storage {

DiskManager::DiskManager(const std::string &db_file) {
}


void DiskManager::WriteData(const std::string key, const char *key_data) {
    db_io_.open(file_name_);
}


}
