#ifndef PCSC_ODE_ADAMBASHFORTHSOLVER_H
#define PCSC_ODE_ADAMBASHFORTHSOLVER_H

#include <functional>
#include <vector>
#include "DiscreteSolver.hh"

/**
 * @file AdamBashforthSolver.h
 * @brief Header file for the AdamBashforthSolver class.
 *
 * This file contains the declaration of the AdamBashforthSolver class,
 * which is a concrete implementation of the DiscreteSolver class for
 * solving Ordinary Differential Equations (ODEs) using the Adam-Bashforth method.
 */

/**
 * @class AdamBashforthSolver
 * @brief Class implementing the Adam-Bashforth method for ODE solving.
 *
 * This class extends DiscreteSolver to provide a solver for Ordinary
 * Differential Equations (ODEs) using the Adam-Bashforth method.
 * It offers a specific implementation of the solve method tailored to this approach.
 */
class AdamBashforthSolver : public DiscreteSolver {
public:
    /**
     * @brief Default constructor for AdamBashforthSolver.
     *
     * Initializes a new instance of AdamBashforthSolver with default parameters.
     */
    AdamBashforthSolver();

    /**
     * @brief Overridden solve method for the Adam-Bashforth method.
     * @return A pair of vectors representing the solution.
     *
     * Implements the pure virtual function from DiscreteSolver.
     * This method applies the Adam-Bashforth method to solve an ODE
     * and returns the solution as a pair of vectors, one for the dependent
     * variable values and the other for the corresponding independent variable values.
     */
    std::pair<std::vector<double>, std::vector<double>> solve() override;
};

#endif // PCSC_ODE_ADAMBASHFORTHSOLVER_H

