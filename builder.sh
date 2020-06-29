#!/bin/bash

checkExistingFolder() {
  if [ -d "$1" ]; then
    :
  else
    mkdir $1
    echo "Creating Build Folder.."
  fi
}

checkExistingFolder ./build && cd ./build && cmake .. && make && exit 0

# build process error
exit 1
