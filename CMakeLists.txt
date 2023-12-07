cmake_minimum_required(VERSION 3.15)
project(PCSC-ODE)

set(CMAKE_CXX_STANDARD 20)

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
target_link_libraries(PCSC-ODE ODE_LIB Boost::iostreams Boost::system Boost::filesystem)



