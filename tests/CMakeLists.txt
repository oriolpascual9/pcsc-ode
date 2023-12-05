cmake_minimum_required(VERSION 3.25)
project(FunctionComponentTests)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories for Google Test and your project
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/../include)

# Add your source files
set(SOURCES
        FunctionComponentTest.cpp
        ../src/FunctionComponent/FunctionComponent.cpp
)

# Create an executable for the tests
add_executable(FunctionComponentTests ${SOURCES})

# Link against Google Test and pthread
target_link_libraries(FunctionComponentTests gtest_main ${GTEST_BOTH_LIBRARIES} pthread)

# Set the output directory for the executable (optional)
set_target_properties(FunctionComponentTests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)