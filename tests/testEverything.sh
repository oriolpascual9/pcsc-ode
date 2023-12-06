#!/bin/bash

# Define the build directory
BUILD_DIR="/home/forestie/Desktop/myfiles/Programmation/Project/ODE/ODE/pcsc-ode/tests/build"

# Remove the build directory if it exists
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

# Recreate the build directory and navigate into it
mkdir "$BUILD_DIR"
cd "$BUILD_DIR"

# Run CMake and make
cmake ..
make

# Execute tests if they exist
for f in bin/*; do
    if [ -x "$f" ]; then
        "$f"
    fi
done


