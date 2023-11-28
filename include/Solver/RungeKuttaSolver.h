#ifndef PCSC_ODE_RUNGEKUTTASOLVER_H
#define PCSC_ODE_RUNGEKUTTASOLVER_H

#include "DiscreteSolver.hh"

class RungeKuttaSolver : public DiscreteSolver {
public:
    virtual double* solve() const override;
};

#endif //PCSC_ODE_RUNGEKUTTASOLVER_H
