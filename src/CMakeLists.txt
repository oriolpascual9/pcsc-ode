add_subdirectory(Problem)
add_subdirectory(Reader)
add_subdirectory(Solver)
add_subdirectory(FunctionComponent)

target_include_directories(ODE_LIB PUBLIC ${PROJECT_SOURCE_DIR}/include)