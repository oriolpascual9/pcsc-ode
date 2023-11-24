#ifndef __READER__HH__
#define __READER__HH__

#include <string>
#include "Problem/Problem.hh"
#include <cassert>

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */

class Reader{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:

  //! Documentation TODO
  Problem read_problem();
  //! Documentation TODO
  double* read_function();

protected:

  //! Documentation TODO
  double* parse_function(std::string function);

  double* create_function(std::vector<std::string> terms);

private:
  virtual Problem read_ODE_Problem() = 0; 
  //! 
  int read_type_of_problem();

};

/* -------------------------------------------------------------------------- */
#endif //__READER__HH__
