#include "GraphOutput.h"
#include <cstdlib>
#include <iostream>

GraphOutput::GraphOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath)
        : AbstractOutput(ys, ts), outputPath(outputPath) {}

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

void GraphOutput::output() const {
    try {
        plot();
    } catch (const Exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
