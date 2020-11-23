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
# TODO: Add CCLS and compile_commands.json build files

if [[ $1 = "debug" ]]; then
  # Debug mode generation for GDB
  cmake -DCMAKE_BUILD_TYPE=Debug .. && exit 0
elif [[ $1 = "make" ]]; then
  # All release flags defined in Cmakelists
  cmake .. && make && exit 0
else
    DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
    $DIR/bin/bashDB "$@"
fi

# process error
exit 1
