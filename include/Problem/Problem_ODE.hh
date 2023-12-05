#ifndef __PROBLEM__ODE__HH__
#define __PROBLEM__ODE__HH__

#include <string>

#include "Solver/DiscreteSolver.hh"
#include "Problem.hh"
#include "Function/Function.h"

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */

class Problem_ODE : public Problem
{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:
    Problem_ODE();
    Problem_ODE(double init_y, double init_t, double delta_t, int n, Function function);
    //! Documentation TODO
    void solve(DiscreteSolver& solver) override;

    // Getter for init_y
    double getInitY() const {
        return init_y;
    }

    // Getter for init_t
    double getInitT() const {
        return init_t;
    }

    // Getter for delta_t
    double getDeltaT() const {
        return delta_t;
    }

    // Getter for n
    int getN() const {
        return n;
    }

private:
    double init_y;
    double init_t;
    double delta_t;
    int n;
    Function function;
    std::pair<std::vector<double>, std::vector<double>> solution;
};

/* -------------------------------------------------------------------------- */
#endif
