#ifndef PCSC_ODE_FUNCTION_H
#define PCSC_ODE_FUNCTION_H

#include<vector>

#include "FunctionComponent/FunctionComponent.h"
#include "ErrorHandler/ExceptionHandler.h"

/**
 * @file Function.h
 * @brief Header file for the Function class.
 *
 * This file contains the declaration of the Function class,
 * which is used to build and manipulate functions in the context
 * of solving Ordinary Differential Equations (ODEs).
 */

/**
 * @class Function
 * @brief Class representing a mathematical function for ODEs.
 *
 * This class encapsulates a mathematical function that can be
 * used in solving Ordinary Differential Equations (ODEs). It consists
 * of a series of function components and operators that together
 * define the function.
 */
class Function {
private:
    std::vector<FunctionComponent> components; ///< Components of the function.
    std::vector<char> operators; ///< Operators used in the function.

public:
    /**
     * @brief Default constructor for Function.
     *
     * Initializes an empty Function object.
     */
    Function(){};

    /**
     * @brief Adds an operator to the function.
     * @param sign The operator to be added (e.g., '+', '-', '*', '/').
     *
     * This method adds a new operator to the list of operators in the function.
     */
    void addOperator(char sign);

    /**
     * @brief Adds a component to the function.
     * @param component The FunctionComponent to be added.
     *
     * This method adds a new component to the function's list of components.
     */
    void addComponent(FunctionComponent component);

    /**
     * @brief Converts the function to a DoubleFunction representation.
     * @return DoubleFunction representation of the function.
     *
     * This method converts the function to a DoubleFunction, which is
     * a numerical representation used for computations.
     */
    DoubleFunction toDoubleFunction() const;

    /**
     * @brief Retrieves the operators of the function.
     * @return A vector of characters representing the operators.
     *
     * This method returns a vector containing the operators used in the function.
     */
    std::vector<char> getOperators();

    /**
     * @brief Retrieves the components of the function.
     * @return A vector of FunctionComponent objects.
     *
     * This method returns a vector containing the components that make up the function.
     */
    std::vector<FunctionComponent> getComponents();

};

#endif //PCSC_ODE_FUNCTION_H

