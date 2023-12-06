#ifndef PCSC_ODE_FUNCTIONCOMPONENT_H
#define PCSC_ODE_FUNCTIONCOMPONENT_H

#include <cmath>
#include <functional>

/**
 * @file FunctionComponent.h
 * @brief Header file for the FunctionComponent class.
 *
 * This file contains the declaration of the FunctionComponent class,
 * which represents individual components of a mathematical function
 * in the context of solving Ordinary Differential Equations (ODEs).
 */

using DoubleFunction = std::function<double(double, double)>;

/**
 * @class FunctionComponent
 * @brief Class representing a component of a mathematical function.
 *
 * This class encapsulates a single component of a mathematical function.
 * It can represent various types of function components like scalar multipliers,
 * polynomial terms, exponential functions, etc., and provides methods
 * to generate and manipulate these components.
 */
class FunctionComponent {
private:
    DoubleFunction functionComponent; ///< The mathematical representation of the function component.

public:
    /**
     * @brief Default constructor for FunctionComponent.
     *
     * Initializes an empty FunctionComponent object.
     */
    FunctionComponent(){}

    /**
     * @brief Generates a scalar component.
     * @param scalar The scalar value of the component.
     *
     * This method sets the function component to a constant scalar value.
     */
    void generateScalarComponent(double scalar);

    /**
     * @brief Generates a polynomial term component.
     * @param scalar The coefficient of the term.
     * @param exponent The exponent of the term.
     *
     * This method creates a polynomial term (e.g., x^n) as the function component.
     */
    void generateTermComponent(double scalar, double exponent);

    /**
     * @brief Generates an exponential component.
     * @param base The base of the exponential component.
     *
     * This method creates an exponential function component (e.g., e^x).
     */
    void generateExpComponent(double base);

    /**
     * @brief Retrieves the function component.
     * @return The DoubleFunction representing the function component.
     *
     * This method returns the mathematical function of the component.
     */
    DoubleFunction getFunction() const;

    /**
     * @brief Sums this component with another.
     * @param other Another FunctionComponent to sum with.
     * @return The resulting FunctionComponent after addition.
     *
     * This method adds another FunctionComponent to this one and returns the result.
     */
    FunctionComponent sum(const FunctionComponent &other) const;
};


#endif //PCSC_ODE_FUNCTIONCOMPONENT_H
