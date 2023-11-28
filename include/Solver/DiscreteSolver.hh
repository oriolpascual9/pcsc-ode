#ifndef DISCRETE_SOLVER_HH
#define DISCRETE_SOLVER_HH

#include "Solver/Solver.hh"

class DiscreteSolver : public Solver<double[]> {
public:
    DiscreteSolver(double (*function)(double, double), double initialY, double deltaTime, int steps)
    : f(function), y0(initialY), dt(deltaTime), n(steps) {}

    virtual double* solve() const override = 0;

protected:
    double (*f)(double, double);
    double y0;
    double dt;
    int n;
};

#endif // DISCRETE_SOLVER_HH
