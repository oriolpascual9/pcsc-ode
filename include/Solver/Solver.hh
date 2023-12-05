#ifndef SOLVER_HH
#define SOLVER_HH

/**
 * @file Solver.hh
 * @brief Header file for the Solver template class.
 *
 * This file contains the declaration of the Solver template class,
 * which serves as a generic abstract base class for solver algorithms.
 * The Solver class is designed to be versatile and can be extended to solve
 * various types of computational problems.
 */

/**
 * @class Solver
 * @brief Abstract base class template for solver algorithms.
 *
 * The Solver class is a template for creating solver classes for various
 * computational problems. It defines a common interface for solvers, with
 * a solve method that must be implemented by derived classes. This design
 * allows for flexibility in the type of solutions that solvers can provide.
 *
 * @tparam T The type of the solution that the solver will produce.
 */
template<typename T>
class Solver {
public:
    /**
     * @brief Default constructor for Solver.
     *
     * Initializes a new instance of Solver. This constructor is typically used
     * by derived classes to set up common solver elements.
     */
    Solver();

    /**
     * @brief Virtual destructor for Solver.
     *
     * Ensures that derived classes can perform proper cleanup upon destruction.
     */
    virtual ~Solver();

    /**
     * @brief Pure virtual solve method.
     * @return The solution of the computational problem, of type T.
     *
     * This pure virtual function must be implemented by derived classes to
     * define the specific solving algorithm and return the solution of the
     * computational problem.
     */
    virtual T solve() = 0;
};

#endif // SOLVER_HH
