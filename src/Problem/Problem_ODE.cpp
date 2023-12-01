#include "Problem/Problem.hh"
#include "Problem/Problem_ODE.hh"
/* -------------------------------------------------------------------------- */
Problem_ODE::Problem_ODE(double init_y, double init_t, double delta_t, int n, Function function) : Problem () {
    this->id = "ODE_test";
    this->init_y = init_y;
    this->init_t = init_t;
    this->delta_t = delta_t;
    this->function = function;
}

void Problem_ODE::solve()
{
}
/* --------------------------------------------------------------------------- */