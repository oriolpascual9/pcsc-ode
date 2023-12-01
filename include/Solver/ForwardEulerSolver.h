#ifndef PCSC_ODE_FORWARDEULERSOLVER_H
#define PCSC_ODE_FORWARDEULERSOLVER_H

#include "DiscreteSolver.hh"
#include <vector>
#include <utility> // For std::pair
#include <functional>

class ForwardEulerSolver : public DiscreteSolver {
public:
    std::pair<std::vector<double>, std::vector<double>> solve() override;
};

#endif //PCSC_ODE_FORWARDEULERSOLVER_H

