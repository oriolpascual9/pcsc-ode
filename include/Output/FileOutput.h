#ifndef FILE_OUTPUT_H
#define FILE_OUTPUT_H

#include "AbstractOutput.h"

#include <fstream>
#include <iostream>

/**
 * @file FileOutput.h
 * @brief Header file for the FileOutput class.
 *
 * This file contains the declaration of the FileOutput class,
 * which is a concrete implementation of the AbstractOutput class
 * for outputting computational results to a file.
 */

/**
 * @class FileOutput
 * @brief Concrete class for outputting data to a file.
 *
 * This class extends AbstractOutput to provide functionality for
 * writing the computational results into a file. It includes methods
 * for creating the data file and overriding the output method to
 * handle file operations.
 */
class FileOutput : public AbstractOutput {
private:
    std::string outputPath; ///< Path of the output file.

    /**
     * @brief Creates a data file for output.
     *
     * This private method is used internally to create a data file
     * at the specified output path. It prepares the file to receive
     * the computational results.
     */
    void createDataFile() const;

public:
    /**
     * @brief Constructor for FileOutput.
     * @param ys The vector of computed values.
     * @param ts The vector of time or independent variable values.
     * @param outputPath The path where the output file will be created.
     *
     * Initializes the FileOutput object with given vectors of computed values,
     * their corresponding times, and the path for the output file.
     */
    FileOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath, std::string id);

    /**
     * @brief Overridden output method for file writing.
     *
     * Implements the pure virtual function from AbstractOutput.
     * This method handles the writing of computational results into
     * the data file specified by outputPath.
     */
    void output() const override; // Implement the virtual function
};

#endif // FILE_OUTPUT_H


