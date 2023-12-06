#ifndef PCSC_ODE_RUNGEKUTTASOLVER_H
#define PCSC_ODE_RUNGEKUTTASOLVER_H

#include "DiscreteSolver.hh"
#include <vector>
#include <utility> // For std::pair

/**
 * @file RungeKuttaSolver.h
 * @brief Header file for the RungeKuttaSolver class.
 *
 * This file contains the declaration of the RungeKuttaSolver class,
 * which is a concrete implementation of the DiscreteSolver class for
 * solving Ordinary Differential Equations (ODEs) using the Runge-Kutta method.
 */

/**
 * @class RungeKuttaSolver
 * @brief Class implementing the Runge-Kutta method for ODE solving.
 *
 * This class extends DiscreteSolver to provide a solver for Ordinary
 * Differential Equations (ODEs) using the Runge-Kutta method.
 * It includes a specific implementation of the solve method tailored
 * to this numerical approach.
 */
class RungeKuttaSolver : public DiscreteSolver {
public:
    /**
     * @brief Default constructor for RungeKuttaSolver.
     *
     * Initializes a new instance of RungeKuttaSolver with default parameters.
     */
    RungeKuttaSolver(){};

    /**
     * @brief Overridden solve method for the Runge-Kutta method.
     * @return A pair of vectors representing the solution.
     *
     * Implements the pure virtual function from DiscreteSolver.
     * This method applies the Runge-Kutta method to solve an ODE
     * and returns the solution as a pair of vectors, one for the dependent
     * variable values and the other for the corresponding independent variable values.
     */
    std::pair<std::vector<double>, std::vector<double>> solve() override;
};

#endif //PCSC_ODE_RUNGEKUTTASOLVER_H

