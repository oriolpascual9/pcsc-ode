#ifndef PCSC_ODE_FORWARDEULERSOLVER_H
#define PCSC_ODE_FORWARDEULERSOLVER_H

#include "DiscreteSolver.hh"

class ForwardEulerSolver : public DiscreteSolver {
public:
    virtual double* solve() const override;
};

#endif //PCSC_ODE_FORWARDEULERSOLVER_H
