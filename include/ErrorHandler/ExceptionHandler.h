#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

/**
 * @file ExceptionHandler.h
 * @brief Header file for the Exception structure.
 *
 * This file contains the declaration of the Exception structure,
 * which is used to handle exceptions in the program.
 */

/**
 * @struct Exception
 * @brief A custom exception structure.
 *
 * This structure is used to represent exceptions that occur within the program.
 * It stores a message and provides a method to retrieve it.
 */
struct Exception {

    /**
     * @brief Constructor for Exception.
     * @param mesg The error message associated with the exception.
     *
     * Initializes a new instance of the Exception structure with a specified error message.
     */
    Exception(const std::string &mesg) : mesg(mesg){};

    /**
     * @brief Retrieves the error message.
     * @return A constant reference to the error message string.
     *
     * Returns the error message associated with the exception.
     */
    const std::string& what() const { return mesg; }

    std::string mesg;  ///< The error message associated with the exception.
};

#endif //EXCEPTION_HANDLER_H
