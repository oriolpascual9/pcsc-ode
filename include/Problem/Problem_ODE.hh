#ifndef __PROBLEM__ODE__HH__
#define __PROBLEM__ODE__HH__

#include <string>

#include "Solver/Solver.hh"
#include "Problem.hh"

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
  Problem_ODE(double init_y, double init_t, double delta_t, int n, double* function);
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
  double* function;
  
};

/* -------------------------------------------------------------------------- */
#endif
