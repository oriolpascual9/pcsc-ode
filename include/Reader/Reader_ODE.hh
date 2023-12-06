#ifndef __READER_ODE__HH__
#define __READER_ODE__HH__

/* -------------------------------------------------------------------------- */
#include <iostream>
#include "Reader.hh"
#include "Solver/AdamBashforthSolver.h"
#include "Solver/BackwardEulerSolver.h"
#include "Solver/ForwardEulerSolver.h"
#include "Solver/RungeKuttaSolver.h"


class Reader_ODE: public Reader
{
public:

  Problem_ODE read_ODE_Problem() override;

  DiscreteSolver& read_discrete_solver() override;

};

/* -------------------------------------------------------------------------- */
#endif //__READER_ODE__HH__
