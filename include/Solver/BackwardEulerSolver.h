#ifndef PCSC_ODE_BACKWARDEULER_H
#define PCSC_ODE_BACKWARDEULER_H

#include "DiscreteSolver.hh"
#include 'ErrorHandler/ExceptionHandler.h'
#include <vector>
#include <utility> // For std::pair

class BackwardEulerSolver : public DiscreteSolver {
public:
    BackwardEulerSolver() {}
    std::pair<std::vector<double>, std::vector<double>> solve() override;

protected:
    double solveBackwardEulerEquation(double y, double t, double dt, DoubleFunction function) const;
};

#endif //PCSC_ODE_BACKWARDEULER_H

