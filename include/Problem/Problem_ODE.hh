#ifndef __PROBLEM__ODE__HH__
#define __PROBLEM__ODE__HH__

#include <string>
#include "Solver/DiscreteSolver.hh"
#include "Problem.hh"
#include "Function/Function.h"
#include <chrono>

/**
 * @file Problem_ODE.hh
 * @brief Header file for the Problem_ODE class.
 *
 * This file contains the declaration of the Problem_ODE class,
 * which is a concrete implementation of the Problem class for
 * solving Ordinary Differential Equations (ODEs).
 */

/**
 * @class Problem_ODE
 * @brief Class representing a problem of solving Ordinary Differential Equations.
 *
 * This class extends the Problem abstract class to handle problems related to
 * Ordinary Differential Equations (ODEs). It includes specific data members
 * relevant to ODEs and overrides the solve method to provide the functionality
 * for solving these types of problems.
 */
class Problem_ODE : public Problem {
public:
    /**
     * @brief Default constructor for Problem_ODE.
     *
     * Initializes a new instance of Problem_ODE with default parameters.
     */
    Problem_ODE();

    // Getter for init_y
    double getInitY() const;

    // Getter for init_t
    double getInitT() const;

    // Getter for delta_t
    double getDeltaT() const;

    // Getter for n
    int getN() const;

    // Getter for function
    Function getFunction() const;

    //Getter for solution
    std::pair<std::vector<double>, std::vector<double>> getSolution() const;

    std::string getID() const;

    /**
     * @brief Parameterized constructor for Problem_ODE.
     * @param init_y Initial value of the dependent variable.
     * @param init_t Initial value of the independent variable.
     * @param delta_t Step size for the independent variable.
     * @param n Number of steps for the solver to take.
     * @param function The function representing the ODE.
     *
     * Initializes a new instance of Problem_ODE with specified parameters for solving an ODE.
     */
    Problem_ODE(double init_y, double init_t, double delta_t, int n, Function function);

    /**
     * @brief Overridden solve method for ODE problems.
     * @param solver Reference to a DiscreteSolver object.
     *
     * Implements the pure virtual function from the Problem class.
     * This method uses the given solver to solve the ODE problem.
     */
    void solve(DiscreteSolver& solver) override;

private:
    double init_y; ///< Initial value of the dependent variable.
    double init_t; ///< Initial value of the independent variable.
    double delta_t; ///< Step size for the independent variable.
    int n; ///< Number of steps for the solver to take.
    Function function; ///< Function representing the ODE.
    std::pair<std::vector<double>, std::vector<double>> solution; ///< The solution of the ODE problem as a pair of vectors for dependent and independent variables.
};

#endif // __PROBLEM__ODE__HH__
