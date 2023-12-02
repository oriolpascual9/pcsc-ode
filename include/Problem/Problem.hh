#ifndef __PROBLEM__HH__
#define __PROBLEM__HH__

#include "Solver/Solver.hh"
#include "Solver/DiscreteSolver.hh"
#include <string>

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */

class Problem{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:
  Problem();
  //! Documentation TODO
  virtual void solve(DiscreteSolver& solver) = 0;


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:
  //!Documentation TODO
  std::string id;

};

/* -------------------------------------------------------------------------- */
#endif //__PROBLEM__HH__
