#ifndef DISCRETE_SOLVER_HH
#define DISCRETE_SOLVER_HH

#include <vector>
#include <utility>  // For std::pair
#include "./Solver.hh"  // Ensure this path is correct

class DiscreteSolver : public Solver<std::pair<std::vector<double>, std::vector<double>>> {
public:
    DiscreteSolver(double (*function)(double, double), double initialY, double deltaTime, int steps)
        : f(function), y0(initialY), dt(deltaTime), n(steps) {}

    virtual std::pair<std::vector<double>, std::vector<double>> solve() const override = 0;

protected:
    double (*f)(double, double);
    double y0;
    double dt;
    int n;
};

#endif // DISCRETE_SOLVER_HH

