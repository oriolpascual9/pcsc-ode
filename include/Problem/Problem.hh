#ifndef __PROBLEM__HH__
#define __PROBLEM__HH__

#include "Solver/Solver.hh"
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
  virtual void solve() = 0;


  /* ------------------------------------------------------------------------ */
  /* Members                                                                  */
  /* ------------------------------------------------------------------------ */

protected:
  //!Documentation TODO
  std::string id;
  //!Documentation TODO
  //Solver solver;
  //!Documentation TODO
  //T solution;

private:


};

/* -------------------------------------------------------------------------- */
#endif //__PROBLEM__HH__
