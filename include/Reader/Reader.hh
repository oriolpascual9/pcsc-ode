#ifndef __READER__HH__
#define __READER__HH__

#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

#include "Problem/Problem.hh"
#include "Problem/Problem_ODE.hh"
#include "Function/Function.h"
#include "FunctionComponent/FunctionComponent.h"
#include "ErrorHandler/ExceptionHandler.h"
#include "Solver/DiscreteSolver.hh"

/* -------------------------------------------------------------------------- */

/**
  * Documentation TODO
  */

class Reader
{

  /* ------------------------------------------------------------------------ */
  /* Methods                                                                  */
  /* ------------------------------------------------------------------------ */

public:
  Reader() {};
  //! Documentation TODO
  Problem& read_problem();

  int read_type_of_output();

  virtual DiscreteSolver& read_discrete_solver() = 0;
  //! Documentation TODO
  Function read_function();
  //! Documentation TODO
  static Function choose_parse_function();
  //! Documentation TODO
  static void parse_function_poly(Function& function, const std::string& input);
  //! Documentation TODO
  static void parse_function_exp(Function& function, const std::string& input);

protected:
  virtual Problem_ODE read_ODE_Problem() = 0;

private:
  int read_type_of_problem();

};

/* -------------------------------------------------------------------------- */
#endif //__READER__HH__
