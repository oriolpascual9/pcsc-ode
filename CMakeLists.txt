cmake_minimum_required(VERSION 3.15)
project(PCSC-ODE)

set(CMAKE_CXX_STANDARD 20)

# Docs only available if this is the main app
find_package(Doxygen)
if(Doxygen_FOUND)
    add_subdirectory(docs)
else()
    message(STATUS "Doxygen not found, not building docs")
endif()

# include the 'src' and 'include' directories
add_subdirectory(src)

# create the executable target
add_executable(PCSC-ODE main.cpp)

# Link the executable with the library created in the 'src' directory
target_link_libraries(PCSC-ODE ODE_LIB)



