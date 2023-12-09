#ifndef __READER__HH__
#define __READER__HH__

#include <string>
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

#include "Problem/Problem.hh"
#include "Problem/Problem_ODE.hh"
#include "Function/Function.h"
#include "FunctionComponent/FunctionComponent.h"
#include "ErrorHandler/ExceptionHandler.h"
#include "Solver/DiscreteSolver.hh"

/**
 * @file Reader.hh
 * @brief Header file for the Reader class.
 *
 * This file contains the declaration of the Reader class, which is used to
 * read and parse input data for setting up computational problems, solvers,
 * and functions.
 */

/**
 * @class Reader
 * @brief Class responsible for reading and parsing input data.
 *
 * The Reader class provides methods for reading and parsing various types of
 * input data necessary for setting up computational problems and their associated
 * solvers and functions. It serves as a base class for more specific reader implementations.
 */
class Reader {
public:
    /**
     * @brief Default constructor for Reader.
     */
    Reader() {};

    /**
     * @brief Reads and constructs a problem instance.
     * @return Reference to the constructed Problem instance.
     */
    Problem& read_problem();

    /**
     * @brief Reads the type of output desired.
     * @return Integer representing the output type.
     */
    int read_type_of_output();

    /**
     * @brief Pure virtual method to read and construct a discrete solver.
     * @return Reference to the constructed DiscreteSolver instance.
     */
    virtual DiscreteSolver& read_discrete_solver() = 0;

    /**
     * @brief Reads and constructs a mathematical function.
     * @return The constructed Function instance.
     */
    Function read_function();

    /**
     * @brief Static method to choose and parse a function based on input.
     * @return The constructed Function instance.
     */
    static Function choose_parse_function();

    /**
     * @brief Static method to parse a polynomial function from a string.
     * @param function Reference to the Function to be populated.
     * @param input String containing the polynomial function representation.
     */
    static void parse_function_poly(Function& function, const std::string& input);

    /**
     * @brief Static method to parse an exponential function from a string.
     * @param function Reference to the Function to be populated.
     * @param input String containing the exponential function representation.
     */
    static void parse_function_exp(Function& function, const std::string& input);

protected:
    /**
     * @brief Pure virtual method to read and construct an ODE problem.
     * @return The constructed Problem_ODE instance.
     */
    virtual Problem_ODE read_ODE_Problem() = 0;

private:
    /**
     * @brief Reads the type of problem to be solved.
     * @return Integer representing the problem type.
     */
    int read_type_of_problem();

};

#endif //__READER__HH__
