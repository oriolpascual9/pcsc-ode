add_library(ODE_LIB)

add_subdirectory(Problem)
add_subdirectory(Reader)
add_subdirectory(Solver)

target_include_directories(ODE_LIB PUBLIC ${PROJECT_SOURCE_DIR}/include)