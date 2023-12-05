#include "Output/GraphOutput.h"
#include <cstdlib>
#include <iostream>

/**
 * @brief Constructor for GraphOutput.
 * @param ys Vector of computed values.
 * @param ts Vector of time or independent variable values.
 * @param outputPath Path where the graph will be saved or displayed.
 *
 * Initializes the GraphOutput object with the provided vectors and output path.
 */
GraphOutput::GraphOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath)
        : AbstractOutput(ys, ts), outputPath(outputPath) {}

/**
 * @brief Creates a plot of the data.
 * @throws Exception If there is an error in creating the data file or executing the plotting command.
 *
 * Generates a plot using GNUplot based on the data stored in the object. The plot is saved to the specified outputPath.
 */
void GraphOutput::plot() const {
    try {
        createDataFile();
    } catch (const Exception &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    std::string gnuplotCommand = "gnuplot -persist -e \"set terminal png size 800,600; "
                                 "set output '" + outputPath + "/plot.png'; "
                                                               "plot '" + outputPath + "/data.dat' using 1:2 with lines\"";
    int result = system(gnuplotCommand.c_str());

    if (result == -1) {
        throw Exception("Error executing GNUplot.");
    }
}

/**
 * @brief Outputs the data as a graph.
 *
 * Calls plot() to generate and save a graphical representation of the data.
 * Catches and reports any exceptions encountered during plotting.
 */
void GraphOutput::output() const {
    try {
        plot();
    } catch (const Exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

