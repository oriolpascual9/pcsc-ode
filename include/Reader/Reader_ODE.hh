#ifndef __READER_ODE__HH__
#define __READER_ODE__HH__

#include <iostream>
#include "Reader.hh"
#include "Solver/AdamBashforthSolver.h"
#include "Solver/BackwardEulerSolver.h"
#include "Solver/ForwardEulerSolver.h"
#include "Solver/RungeKuttaSolver.h"

/**
 * @file Reader_ODE.hh
 * @brief Header file for the Reader_ODE class.
 *
 * This file contains the declaration of the Reader_ODE class,
 * a subclass of Reader specifically designed for reading and parsing
 * input data related to Ordinary Differential Equation (ODE) problems.
 */

/**
 * @class Reader_ODE
 * @brief Class specialized in reading and parsing ODE problems.
 *
 * Reader_ODE extends the Reader class and provides specific implementations
 * for methods that read and construct ODE problems and their associated discrete solvers.
 */
class Reader_ODE: public Reader {
public:
    /**
     * @brief Reads and constructs an ODE problem.
     * @return The constructed Problem_ODE instance.
     *
     * Overrides the read_ODE_Problem method to specifically handle the reading
     * and construction of ODE problems.
     */
    Problem_ODE read_ODE_Problem() override;

    /**
     * @brief Reads and constructs a discrete solver suitable for ODEs.
     * @return Reference to the constructed DiscreteSolver instance.
     *
     * Overrides the read_discrete_solver method to provide specific solvers
     * suitable for solving ODE problems, such as Adam-Bashforth, Backward Euler,
     * Forward Euler, and Runge-Kutta solvers.
     */
    DiscreteSolver& read_discrete_solver() override;

};

#endif //__READER_ODE__HH__
