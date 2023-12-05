#ifndef DISCRETE_SOLVER_HH
#define DISCRETE_SOLVER_HH

#include <vector>
#include <utility>  // For std::pair
#include "./Solver.hh"  // Ensure this path is correct
#include "Function/Function.h"

/**
 * @file DiscreteSolver.hh
 * @brief Header file for the DiscreteSolver class.
 *
 * This file contains the declaration of the DiscreteSolver class,
 * which is an abstract base class for discrete solvers of Ordinary Differential Equations (ODEs).
 */

/**
 * @class DiscreteSolver
 * @brief Abstract base class for discrete ODE solvers.
 *
 * DiscreteSolver serves as a base class for various discrete solvers
 * used in solving Ordinary Differential Equations. It provides a common interface
 * and shared functionality for discrete solvers, while leaving the specific
 * solving algorithm to be implemented by derived classes.
 */
class DiscreteSolver : public Solver<std::pair<std::vector<double>, std::vector<double>>> {
public:
    /**
     * @brief Constructor for DiscreteSolver with parameters.
     * @param function The function representing the ODE to be solved.
     * @param initialY Initial value of the dependent variable.
     * @param deltaTime Step size for the solver.
     * @param steps Number of steps to be taken by the solver.
     *
     * Initializes a new instance of DiscreteSolver with specific parameters
     * for solving an ODE.
     */
    DiscreteSolver(Function function, double initialY, double deltaTime, int steps);

    /**
     * @brief Default constructor for DiscreteSolver.
     *
     * Initializes a new instance of DiscreteSolver with default values.
     */
    DiscreteSolver();

    /**
     * @brief Pure virtual solve method.
     * @return A pair of vectors representing the solution.
     *
     * This pure virtual function should be implemented by derived classes to
     * solve the ODE using specific algorithms and return the solution.
     */
    virtual std::pair<std::vector<double>, std::vector<double>> solve() override = 0;

    void setFunction(Function function);
    void setInitialY(double y);
    void setDeltaT(double dt);
    void setN(int n);

protected:
    Function function; ///< Function representing the ODE to be solved.
    double y0;        ///< Initial value of the dependent variable.
    double dt;        ///< Step size for the solver.
    int n;            ///< Number of steps to be taken by the solver.
};

#endif // DISCRETE_SOLVER_HH


