cmake_minimum_required(VERSION 3.16)
project(tests)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)

####################### FETCH BOOST

set(BOOST_INCLUDE_LIBRARIES filesystem system iostreams)
set(BOOST_ENABLE_CMAKE ON)

# Download and extract the boost library from GitHub
message(STATUS "Downloading and extracting boost library sources. This will take some time...")
include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE) # Needed to print downloading progress
FetchContent_Declare(
        Boost
        URL https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.7z # downloading a zip release speeds up the download
        USES_TERMINAL_DOWNLOAD TRUE
        GIT_PROGRESS TRUE
        DOWNLOAD_NO_EXTRACT FALSE
)
FetchContent_MakeAvailable(Boost)

####################### FETCH GOOGLETEST

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

######################


# adds the search path for includes
include_directories(${PROJECT_SOURCE_DIR}/../gnuplot-iostream)

# Include directories for Google Test and your project
include_directories(${PROJECT_SOURCE_DIR}/../include)

include_directories(${Boost_INCLUDE_DIRS})
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
## READER ODE
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


######################################
## FILE OUTPUT
######################################

# Add your source files
set(SOURCES_FILE_OUTPUT
        FileOutputTest.cpp
        ../src/Output/FileOutput.cpp
        ../src/Output/AbstractOutput.cpp
)

# Create an executable for the tests
add_executable(FileOutputTests ${SOURCES_FILE_OUTPUT})

# Link against Google Test and pthread
target_link_libraries(FileOutputTests gtest_main ${GTEST_BOTH_LIBRARIES} pthread)

# Set the output directory for the executable (optional)
set_target_properties(FileOutputTests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

######################################
## GRAPH OUTPUT
######################################

# Add your source files
#set(SOURCES_GRAPH_OUTPUT
#        GraphOutputTest.cpp
#        ../src/Output/GraphOutput.cpp
#        ../src/Output/FileOutput.cpp
#        ../src/Output/AbstractOutput.cpp
#)

# Create an executable for the tests
#add_executable(GraphOutputTests ${SOURCES_GRAPH_OUTPUT})

# Link against Google Test and pthread
#target_link_libraries(GraphOutputTests
#        gtest_main
#        ${GTEST_BOTH_LIBRARIES}
#        pthread
#        Boost::iostreams
#        Boost::system
#        Boost::filesystem
#)

# Set the output directory for the executable (optional)
#set_target_properties(GraphOutputTests PROPERTIES
        #RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#)

######################################
## SOLVERS
######################################

# Add your source files
set(SOURCES_SOLVERS
        SolversTest.cpp
        ../src/Solver/DiscreteSolver.cpp
        ../src/Solver/AdamBashforthSolver.cpp
        ../src/Solver/BackwardEulerSolver.cpp
        ../src/Solver/ForwardEulerSolver.cpp
        ../src/Solver/RungeKuttaSolver.cpp
        ../src/Function/Function.cpp
        ../src/FunctionComponent/FunctionComponent.cpp
)

# Create an executable for the tests
add_executable(SolverTests ${SOURCES_SOLVERS})

# Link against Google Test and pthread
target_link_libraries(SolverTests
        gtest_main
        ${GTEST_BOTH_LIBRARIES}
        pthread
)

# Set the output directory for the executable (optional)
set_target_properties(SolverTests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)