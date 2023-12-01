#ifndef PCSC_ODE_BACKWARDEULER_H
#define PCSC_ODE_BACKWARDEULER_H

#include "DiscreteSolver.hh"
#include <vector>
#include <utility> // For std::pair

class BackwardEulerSolver : public DiscreteSolver {
public:
    virtual std::pair<std::vector<double>, std::vector<double>> solve() const override;

protected:
    double solveBackwardEulerEquation(double y, double t, double dt, double (*f)(double, double)) const;
};

#endif //PCSC_ODE_BACKWARDEULER_H

