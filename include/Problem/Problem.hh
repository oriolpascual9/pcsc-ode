#ifndef __PROBLEM__HH__
#define __PROBLEM__HH__

#include "Solver/Solver.hh"
#include "Solver/DiscreteSolver.hh"
#include <string>

/**
 * @file Problem.hh
 * @brief Header file for the Problem class.
 *
 * This file contains the declaration of the Problem class,
 * which serves as an abstract base class for representing different
 * types of computational problems to be solved.
 */

/**
 * @class Problem
 * @brief Abstract base class representing a computational problem.
 *
 * This abstract class provides the framework for defining a computational
 * problem. It contains the core functionalities and interfaces that are
 * common to various types of problems. Derived classes are expected to
 * implement specific problem-solving strategies.
 */
class Problem {
public:
    /**
     * @brief Constructor for Problem.
     *
     * Initializes a new instance of a Problem. This constructor is typically
     * used by derived classes to set up common problem elements.
     */
    Problem();

    /**
     * @brief Pure virtual function to solve the problem.
     * @param solver Reference to a DiscreteSolver object.
     *
     * This pure virtual function should be implemented by derived classes to
     * define how the problem is solved using a given solver.
     */
    virtual void solve(DiscreteSolver& solver) = 0;

protected:
    std::string id; ///< Unique identifier for the problem instance.
};

#endif //__PROBLEM__HH__

