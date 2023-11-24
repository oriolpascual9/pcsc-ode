#ifndef DISCRETE_SOLVER_HH
#define DISCRETE_SOLVER_HH

#include "Solver.hh"

template<typename T>
class DiscreteSolver : public Solver<T> {
public:
    DiscreteSolver(double (*function)(double, T), T initialY, double deltaTime, int steps)
    : f(function), y0(initialY), dt(deltaTime), n(steps) {}

protected:
    double (*f)(double, T);
    T y0;
    double dt;
    int n;
};

#endif // DISCRETE_SOLVER_HH
