#include "Output/GraphOutput.h"

/**
 * @brief Constructor for GraphOutput.
 * @param ys Vector of computed values.
 * @param ts Vector of time or independent variable values.
 * @param outputPath Path where the graph will be saved or displayed.
 *
 * Initializes the GraphOutput object with the provided vectors and output path.
 */
GraphOutput::GraphOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath, std::string id)
        : AbstractOutput(ys, ts, id), outputPath(outputPath) {}

/**
 * @brief Creates a plot of the data.
 * @throws Exception If there is an error in creating the data file or executing the plotting command.
 *
 * Generates a plot using GNUplot based on the data stored in the object. The plot is saved to the specified outputPath.
 */
void GraphOutput::plot() const {
    FileOutput fileOutput(ys, ts, outputPath, id);
    fileOutput.output();
    Gnuplot gp;
    // Sets the terminal and output file
    gp << "set terminal png size 800,600\n";
    gp << "set output '" << outputPath << "/" << id << ".png'\n";
    // Plots the data from the file
    gp << "plot '" << outputPath << "/"<< id << "using 1:2 with lines\n";
}

/**
 * @brief Outputs the data as a graph.
 *
 * Calls plot() to generate and save a graphical representation of the data.
 * Catches and reports any exceptions encountered during plotting.
 */
void GraphOutput::output() const {
    plot();
}

