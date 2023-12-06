#include "Reader/Reader_ODE.hh"
/* -------------------------------------------------------------------------- */

Problem_ODE Reader_ODE::read_ODE_Problem(){
    double init_y, init_t, delta_t;
    int n;
    std::cout << "Please enter initial conditions for the ODE problem\n";
    std::cout << "Initial y:\n";
    std::cin >> init_y;

    std::cout << "Initial t:\n";
    std::cin >> init_t;

    std::cout << "Timestep:\n";
    std::cin >> delta_t;

    std::cout << "Number of steps:\n";
    std::cin >> n;
    // assert if there are some restrictions to the variables
    
    Function function;
    function = Reader::choose_parse_function();
    
    return Problem_ODE(init_y, init_t, delta_t, n, function);
}

/* --------------------------------------------------------------------------- */


