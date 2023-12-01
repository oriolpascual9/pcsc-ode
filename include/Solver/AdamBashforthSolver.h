#ifndef PCSC_ODE_ADAMBASHFORTHSOLVER_H
#define PCSC_ODE_ADAMBASHFORTHSOLVER_H

#include <functional>
#include <vector>
#include "DiscreteSolver.hh"

class AdamBashforthSolver : public DiscreteSolver<double> {
public:
    // Constructor without initialMethod
    AdamBashforthSolver(double (*function)(double, double), double initialY, double deltaTime, int steps)
        : DiscreteSolver<double>(function, initialY, deltaTime, steps) {}

    virtual std::pair<std::vector<double>, std::vector<double>> solve() const override;
};

#endif

