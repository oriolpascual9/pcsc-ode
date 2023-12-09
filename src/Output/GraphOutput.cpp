#include "Output/GraphOutput.h"

GraphOutput::GraphOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath, std::string id)
        : AbstractOutput(ys, ts, id), outputPath(outputPath) {}

void GraphOutput::plot() const {
    FileOutput fileOutput(ys, ts, outputPath, id);
    fileOutput.output();
    Gnuplot gp;
    // Sets the terminal and output file
    gp << "set terminal png size 800,600\n";
    gp << "set output '" << outputPath << "/" << id << ".png'\n";
    // Plots the data from the file
    gp << "plot '" << outputPath << "/"<< id << ".dat' using 1:2 with lines\n";
}


void GraphOutput::output() const {
    plot();
}

