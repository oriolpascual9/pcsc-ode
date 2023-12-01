#ifndef PCSC_ODE_FORWARDEULERSOLVER_H
#define PCSC_ODE_FORWARDEULERSOLVER_H

#include "DiscreteSolver.hh"
#include <vector>
#include <utility> // For std::pair

class ForwardEulerSolver : public DiscreteSolver {
public:
    virtual std::pair<std::vector<double>, std::vector<double>> solve() const override;
};

#endif //PCSC_ODE_FORWARDEULERSOLVER_H

