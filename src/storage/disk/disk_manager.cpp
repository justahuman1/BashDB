#pragma once

#include <iostream>
#include <cassert>
#include <fstream>
#include <storage/disk/disk_manager.hpp>

namespace Storage {

static char *buffer_used;

DiskManager::DiskManager(const std::string &db_file)
  : file_name_(db_file){
  db_io_.open(db_file, std::ios::binary | std::ios::in | std::ios::out | std::ios::out);

  // directory or file does not exist
  if (!db_io_.is_open()) {
    db_io_.clear();
    // create a new file
    db_io_.open(db_file, std::ios::binary | std::ios::trunc | std::ios::out);
    db_io_.close();
    // reopen with original mode
    db_io_.open(db_file, std::ios::binary | std::ios::in | std::ios::out);
  }

  buffer_used = nullptr;
}

/**
 * Write key data to file (append to file)
 */

void DiskManager::WriteData(const std::string key, const char *key_data) {
  // enforce swap log buffer
  assert(buffer_used == NULL);
  char m = '1';
  buffer_used = &m;
  db_io_.open(file_name_);
  // TODO
  // Need to dynamically write streamsize.
  // Otherwise, too much data may be consumed.
  db_io_.write(key_data, 32);
}

/**
 * Close all file streams
 */
void DiskManager::ShutDown() {
  db_io_.close();
}

}
