cmake_minimum_required(VERSION 3.16)
project(tests)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories for Google Test and your project
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/../include)

######################################
## FUNCTION COMPONENT
######################################

# Add your source files
set(SOURCES_FUNCTIONCOMPONENT
        FunctionComponentTest.cpp
        ../src/FunctionComponent/FunctionComponent.cpp
)

# Create an executable for the tests
add_executable(FunctionComponentTests ${SOURCES_FUNCTIONCOMPONENT})

# Link against Google Test and pthread
target_link_libraries(FunctionComponentTests gtest_main ${GTEST_BOTH_LIBRARIES} pthread)

# Set the output directory for the executable (optional)
set_target_properties(FunctionComponentTests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

######################################
## FUNCTION
######################################

# Add your source files
set(SOURCES_FUNCTION
        FunctionTest.cpp
        ../src/Function/Function.cpp
        ../src/FunctionComponent/FunctionComponent.cpp

)

# Create an executable for the tests
add_executable(FunctionTests ${SOURCES_FUNCTION})

# Link against Google Test and pthread
target_link_libraries(FunctionTests gtest_main ${GTEST_BOTH_LIBRARIES} pthread)

# Set the output directory for the executable (optional)
set_target_properties(FunctionTests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

######################################
## READER
######################################

# Add your source files
set(SOURCES_READER_ODE
        Reader_ODETest.cpp
        ../src/Reader/Reader.cpp
        ../src/Reader/Reader_ODE.cpp
        ../src/Function/Function.cpp
        ../src/FunctionComponent/FunctionComponent.cpp
        ../src/Problem/Problem.cpp
        ../src/Problem/Problem_ODE.cpp
        ../src/Solver/DiscreteSolver.cpp
)

# Create an executable for the tests
add_executable(ReaderODETests ${SOURCES_READER_ODE})

# Link against Google Test and pthread
target_link_libraries(ReaderODETests gtest_main ${GTEST_BOTH_LIBRARIES} pthread)

# Set the output directory for the executable (optional)
set_target_properties(ReaderODETests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
