#ifndef OUTPUT_HANDLER_H
#define OUTPUT_HANDLER_H

#include "Output/FileOutput.h"
#include "Output/GraphOutput.h"
#include <memory> // For std::unique_ptr

/**
 * @file OutputHandler.h
 * @brief Header file for the OutputHandler class.
 *
 * This file contains the declaration of the OutputHandler class, which is
 * responsible for handling the generation of output based on the specified output type.
 */

/**
 * @class OutputHandler
 * @brief Class responsible for managing the output of computational results.
 *
 * OutputHandler facilitates the creation and management of output, whether it's
 * file output or graphical output. It utilizes the AbstractOutput class and its
 * derivatives to generate the desired form of output based on provided data.
 */
class OutputHandler {
public:
    /**
     * @brief Constructor for OutputHandler.
     * @param outputType Type of output to be generated (file, graph, etc.).
     * @param solution Pair of vectors representing the solution data.
     * @param outputPath Path for saving the output.
     * @param ID Identifier for the output (can be used in naming files or titles).
     *
     * Initializes an OutputHandler object with the specified output type, solution data,
     * output path, and an identifier.
     */
    OutputHandler(int outputType, const std::pair<std::vector<double>, std::vector<double>>& solution, const std::string& outputPath, const std::string& ID);

    /**
     * @brief Generates the specified output.
     *
     * Depending on the output type specified in the constructor, this method
     * generates either a file output or a graphical output using the solution data.
     */
    void generateOutput();

private:
    std::unique_ptr<AbstractOutput> outputPtr; ///< Pointer to the AbstractOutput object for handling output generation.
};

#endif // OUTPUT_HANDLER_H
