#!/bin/bash

# Recreate the build directory and navigate into it
mkdir build
cd build

# Run CMake and make
cmake ..
make

# Execute tests if they exist
for f in bin/*; do
    if [ -x "$f" ]; then
        "$f"
    fi
done


