add_library(ODE_LIB)

add_subdirectory(Problem)
add_subdirectory(Reader)
add_subdirectory(Solver)
add_subdirectory(FunctionComponent)
add_subdirectory(Function)
add_subdirectory(Output)
add_subdirectory(OutputHandler)

target_include_directories(ODE_LIB PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/gnuplot-iostream)