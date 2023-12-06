#ifndef GRAPH_OUTPUT_H
#define GRAPH_OUTPUT_H

#include "AbstractOutput.h"
#include "FileOutput.h"
#include "ErrorHandler/ExceptionHandler.h"
#include <cstdlib>
#include <iostream>
#include "gnuplot-iostream.h"

/**
 * @file GraphOutput.h
 * @brief Header file for the GraphOutput class.
 *
 * This file contains the declaration of the GraphOutput class,
 * which is a concrete implementation of the AbstractOutput class
 * for visualizing computational results in a graphical format.
 */

/**
 * @class GraphOutput
 * @brief Concrete class for outputting data as a graph.
 *
 * This class extends AbstractOutput to provide functionality for
 * visualizing the computational results in a graph. It includes methods
 * for plotting the data and overriding the output method to handle
 * graphical display operations.
 */
class GraphOutput : public AbstractOutput {
private:
    std::string outputPath; ///< Path where the graph will be saved or displayed.

    /**
     * @brief Creates a plot of the data.
     *
     * This private method is used internally to generate a graph plot
     * of the computational results. The plot is saved or displayed at
     * the location specified by outputPath.
     */
    void plot() const;

public:
    /**
     * @brief Constructor for GraphOutput.
     * @param ys The vector of computed values.
     * @param ts The vector of time or independent variable values.
     * @param outputPath The path where the graph will be saved or displayed.
     *
     * Initializes the GraphOutput object with given vectors of computed values,
     * their corresponding times, and the path for the graph output.
     */
    GraphOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath, std::string id);

    /**
     * @brief Overridden output method for graph plotting.
     *
     * Implements the pure virtual function from AbstractOutput.
     * This method handles the creation and display of a graph plot
     * based on the computational results.
     */
    void output() const override; // Implement the virtual function
};

#endif // GRAPH_OUTPUT_H


