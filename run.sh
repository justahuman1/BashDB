#!/bin/bash

checkExistingFolder() {
  if [ -d "$1" ]; then
    :
  else
    mkdir $1
    echo "Creating Build Folder.."
  fi
}

# Create build folder if not exists
checkExistingFolder ./build && cd ./build

if [[ $1 = "debug" ]]; then
  # Debug mode generation for GDB
  cmake -DCMAKE_BUILD_TYPE=Debug .. && exit 0
else
  # All release flags defined in Cmakelists
  cmake .. && make && exit 0
fi

# build process error
exit 1
