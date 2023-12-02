cmake_minimum_required(VERSION 3.10)
project(FunctionComponentTests)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories for Google Test
include_directories(${GTEST_INCLUDE_DIRS})

# Add your source files
set(SOURCES
        FunctionComponentTest.cpp  # Your test file
        FunctionComponent/FunctionComponent.cpp  # Your FunctionComponent implementation
)

# Create an executable for the tests
add_executable(FunctionComponentTests ${SOURCES})

# Link against Google Test and pthread
target_link_libraries(FunctionComponentTests ${GTEST_BOTH_LIBRARIES} pthread)

# Set the output directory for the executable (optional)
set_target_properties(FunctionComponentTests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)