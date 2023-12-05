#ifndef PCSC_ODE_FORWARDEULERSOLVER_H
#define PCSC_ODE_FORWARDEULERSOLVER_H

#include "DiscreteSolver.hh"
#include <vector>
#include <utility> // For std::pair
#include <functional>

/**
 * @file ForwardEulerSolver.h
 * @brief Header file for the ForwardEulerSolver class.
 *
 * This file contains the declaration of the ForwardEulerSolver class,
 * which is a concrete implementation of the DiscreteSolver class for
 * solving Ordinary Differential Equations (ODEs) using the Forward Euler method.
 */

/**
 * @class ForwardEulerSolver
 * @brief Class implementing the Forward Euler method for ODE solving.
 *
 * This class extends DiscreteSolver to provide a solver for Ordinary
 * Differential Equations (ODEs) using the Forward Euler method.
 * It specifically implements the solve method tailored to this numerical approach.
 */
class ForwardEulerSolver : public DiscreteSolver {
public:
    /**
     * @brief Default constructor for ForwardEulerSolver.
     *
     * Initializes a new instance of ForwardEulerSolver with default parameters.
     */
    ForwardEulerSolver();

    /**
     * @brief Overridden solve method for the Forward Euler method.
     * @return A pair of vectors representing the solution.
     *
     * Implements the pure virtual function from DiscreteSolver.
     * This method applies the Forward Euler method to solve an ODE
     * and returns the solution as a pair of vectors, one for the dependent
     * variable values and the other for the corresponding independent variable values.
     */
    std::pair<std::vector<double>, std::vector<double>> solve() override;
};

#endif //PCSC_ODE_FORWARDEULERSOLVER_H


