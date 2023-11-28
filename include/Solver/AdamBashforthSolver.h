#ifndef PCSC_ODE_ADAMBASHFORTHSOLVER_H
#define PCSC_ODE_ADAMBASHFORTHSOLVER_H

#include <functional>

#include "DiscreteSolver.hh"

class AdamBashforthSolver : public DiscreteSolver {
public:
    AdamBashforthSolver(double (*function)(double, double), double initialY, double deltaTime, int steps, std::function<double(DiscreteSolver<double>&)> initialMethod)
            : DiscreteSolver<double>(function, initialY, deltaTime, steps), initialMethod(initialMethod) {}

    virtual double* solve() const override;

private:
    std::function<T(DiscreteSolver<double[]>&)> initialMethod;
};

#endif
