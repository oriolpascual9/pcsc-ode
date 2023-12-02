#ifndef DISCRETE_SOLVER_HH
#define DISCRETE_SOLVER_HH

#include <vector>
#include <utility>  // For std::pair
#include "./Solver.hh"  // Ensure this path is correct
#include "Function/Function.h"

class DiscreteSolver : public Solver<std::pair<std::vector<double>, std::vector<double>>> {
public:
    DiscreteSolver(Function function, double initialY, double deltaTime, int steps)
        : function(function), y0(initialY), dt(deltaTime), n(steps) {}

    DiscreteSolver() {}

    virtual std::pair<std::vector<double>, std::vector<double>> solve() override = 0;

    void setFunction(Function function);
    void setInitialY(double y);
    void setDeltaT(double dt);
    void setN(int n);

protected:
    Function function;
    double y0;
    double dt;
    int n;
};

#endif // DISCRETE_SOLVER_HH

