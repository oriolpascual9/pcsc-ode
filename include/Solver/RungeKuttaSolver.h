#ifndef PCSC_ODE_RUNGEKUTTASOLVER_H
#define PCSC_ODE_RUNGEKUTTASOLVER_H

#include "DiscreteSolver.hh"
#include <vector>
#include <utility> // For std::pair

class RungeKuttaSolver : public DiscreteSolver {
public:
    virtual std::pair<std::vector<double>, std::vector<double>> solve() override;
};

#endif //PCSC_ODE_RUNGEKUTTASOLVER_H

