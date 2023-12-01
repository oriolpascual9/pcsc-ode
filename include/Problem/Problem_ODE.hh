#ifndef __PROBLEM__ODE__HH__
#define __PROBLEM__ODE__HH__

#include <string>

#include "Solver/Solver.hh"
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
    virtual void solve();


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

private:
    double init_y;
    double init_t;
    double delta_t;
    int n;
    Function function;
};

/* -------------------------------------------------------------------------- */
#endif
