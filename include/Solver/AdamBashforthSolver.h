#ifndef PCSC_ODE_ADAMBASHFORTHSOLVER_H
#define PCSC_ODE_ADAMBASHFORTHSOLVER_H

#include <functional>
#include <vector>
#include "DiscreteSolver.hh"

class AdamBashforthSolver : public DiscreteSolver {
public:
    AdamBashforthSolver() {}
    std::pair<std::vector<double>, std::vector<double>> solve() override;
};

#endif

