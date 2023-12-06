#ifndef ABSTRACT_OUTPUT_H
#define ABSTRACT_OUTPUT_H

#include <vector>
#include <string>
#include "ErrorHandler/ExceptionHandler.h"
#include <filesystem>

/**
 * @file AbstractOutput.h
 * @brief Header file for the AbstractOutput class.
 *
 * This file contains the declaration of the AbstractOutput class,
 * which is an abstract base class for outputting the results of
 * computations, particularly in the context of differential equations.
 */

/**
 * @class AbstractOutput
 * @brief Abstract base class for output handling.
 *
 * This abstract class defines the interface for outputting computational
 * results. It holds the computed values and provides a pure virtual function
 * for outputting these values in a specific format.
 */
class AbstractOutput {
protected:
    std::vector<double> ys; ///< Computed values.
    std::vector<double> ts; ///< Corresponding time or independent variable values.

public:
    /**
     * @brief Constructor for AbstractOutput.
     * @param ys The vector of computed values.
     * @param ts The vector of time or independent variable values.
     *
     * Initializes the AbstractOutput with given vectors of computed values and their corresponding times.
     */
    AbstractOutput(const std::vector<double>& ys, const std::vector<double>& ts);

    /**
     * @brief Virtual destructor for AbstractOutput.
     *
     * Destroys the AbstractOutput instance. As this is an abstract class,
     * the destructor is virtual to ensure proper cleanup in derived classes.
     */
    virtual ~AbstractOutput() = default;

    /**
     * @brief Pure virtual function for outputting results.
     *
     * This method must be implemented by derived classes to output
     * the computational results in a specific format.
     */
    virtual void output() const = 0; // Pure virtual function
};

#endif // ABSTRACT_OUTPUT_H


