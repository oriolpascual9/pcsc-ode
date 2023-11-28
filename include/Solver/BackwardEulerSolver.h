#ifndef PCSC_ODE_BACKWARDEULER_H
#define PCSC_ODE_BACKWARDEULER_H

#include "DiscreteSolver.hh"

class BackwardEulerSolver : public DiscreteSolver {
public:
    virtual double* solve() const override;

private:
    double solveBackwardEulerEquation(double y, double t, double dt, double (*f)(double, double)) const;
};


#endif //PCSC_ODE_BACKWARDEULER_H
