#ifndef PCSC_ODE_BACKWARDEULER_H
#define PCSC_ODE_BACKWARDEULER_H

#include "DiscreteSolver.hh"
#include "ErrorHandler/ExceptionHandler.h"
#include <vector>
#include <utility> // For std::pair

/**
 * @file BackwardEulerSolver.h
 * @brief Header file for the BackwardEulerSolver class.
 *
 * This file contains the declaration of the BackwardEulerSolver class,
 * which is a concrete implementation of the DiscreteSolver class for
 * solving Ordinary Differential Equations (ODEs) using the Backward Euler method.
 */

/**
 * @class BackwardEulerSolver
 * @brief Class implementing the Backward Euler method for ODE solving.
 *
 * This class extends DiscreteSolver to provide a solver for Ordinary
 * Differential Equations (ODEs) using the Backward Euler method.
 * It includes an implementation of the solve method and a protected
 * method for solving the Backward Euler equation.
 */
class BackwardEulerSolver : public DiscreteSolver {
public:
    /**
     * @brief Default constructor for BackwardEulerSolver.
     *
     * Initializes a new instance of BackwardEulerSolver with default parameters.
     */
    BackwardEulerSolver(){};

    /**
     * @brief Overridden solve method for the Backward Euler method.
     * @return A pair of vectors representing the solution.
     *
     * Implements the pure virtual function from DiscreteSolver.
     * This method applies the Backward Euler method to solve an ODE
     * and returns the solution as a pair of vectors, one for the dependent
     * variable values and the other for the corresponding independent variable values.
     */
    std::pair<std::vector<double>, std::vector<double>> solve() override;

protected:
    /**
     * @brief Implements the Newton method to solve for y_n+1 in the Backward Euler equation.
     * @param y Current value of the dependent variable.
     * @param t Current value of the independent variable.
     * @param dt Step size.
     * @param function The function representing the ODE.
     * @return The value of the dependent variable at the next step (y_n+1).
     *
     * This method utilizes the Newton method to iteratively solve for the value of y_n+1,
     * which is the value of the dependent variable at the next step in the Backward Euler
     * method. The function uses the current values of the dependent and independent variables,
     * step size, and the ODE function to calculate this value.
     */
    double solveBackwardEulerEquation(double y, double t, double dt, DoubleFunction function) const;
};

#endif //PCSC_ODE_BACKWARDEULER_H
