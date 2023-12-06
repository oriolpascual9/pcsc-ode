#include "Problem/Problem.hh"
#include "Problem/Problem_ODE.hh"
/* -------------------------------------------------------------------------- */
Problem_ODE::Problem_ODE(double init_y, double init_t, double delta_t, int n, Function function) : Problem () {
    std::chrono::milliseconds ms = duration_cast< std::chrono::milliseconds >(
        std::chrono::system_clock::now().time_since_epoch()
    );
    this->id = "ODE_" + std::to_string(ms.count());
    this->init_y = init_y;
    this->init_t = init_t;
    this->delta_t = delta_t;
    this->n = n;
    this->function = function;
}

void Problem_ODE::solve(DiscreteSolver& solver)
{
    solver.setFunction(function);
    solver.setDeltaT(delta_t);
    solver.setInitialY(init_y);
    solver.setN(n);
    solution = solver.solve();
}


// Getter for init_y
double Problem_ODE::getInitY() const {
    return init_y;
}

// Getter for init_t
double Problem_ODE::getInitT() const {
    return init_t;
}

// Getter for delta_t
double Problem_ODE::getDeltaT() const {
    return delta_t;
}

// Getter for n
int Problem_ODE::getN() const {
    return n;
}

Function Problem_ODE::getFunction() const {
    return function;
}

/* --------------------------------------------------------------------------- */