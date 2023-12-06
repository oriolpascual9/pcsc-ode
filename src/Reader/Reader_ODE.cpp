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

DiscreteSolver& Reader_ODE::read_discrete_solver() {
    std::cout << "Please select the ODE Solver\n";
    std::cout << "  1. AdamsBashforth solver\n";
    std::cout << "  2. BackwardEuler solver\n";
    std::cout << "  3. ForwardEuler solver\n";
    std::cout << "  4. RungaKutta solver\n";

    int n;
    std::cin >> n;

    DiscreteSolver* solver = nullptr;
    switch(n) {
        case 1: {
            solver = new AdamBashforthSolver();
        }
        case 2: {
            solver = new BackwardEulerSolver();
        }
        case 3: {
            solver = new ForwardEulerSolver();
        }
        case 4: {
            solver = new RungeKuttaSolver();
        }
        default:
            throw Exception("Number of solver not supported");
    }
    return *solver;
}

/* --------------------------------------------------------------------------- */


