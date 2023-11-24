#ifndef __PROBLEM__ODE__HH__
#define __PROBLEM__ODE__HH__

#include<solver.hh>
#include<string>
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
  Problem_ODE(double init_y, double init_t, double delta_t, int n, double* function);
  //! Documentation TODO
  virtual void solve();


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:

  //!Documentation TODO
  int id;
  //!Documentation TODO
  //Solver solver;
  //!Documentation TODO
  std::string output_method;
  //!Documentation TODO
  //T solution;

private:
  double init_y;
  double init_t;
  double delta_t;
  int n;
  double* function;
  
};

/* -------------------------------------------------------------------------- */
#endif
