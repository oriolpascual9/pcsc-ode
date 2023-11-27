cmake_minimium_required(VERSION 3.5)
project(reader)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES  ${PROJECT_SOURCE_DIR}/*.cpp)
foreach(f ${SOURCES})
  get_filename_component(basename ${f} NAME_WE)
  get_filename_component(dir ${f} DIRECTORY)
  add_executable(${basename} ${f})
endforeach()
