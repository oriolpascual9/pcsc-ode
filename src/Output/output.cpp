#include "output.hh"
#include <cstdlib>

Output::Output(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath)
    : ys(ys), ts(ts), outputPath(outputPath) {}

void Output::createDataFile() const {
    std::ofstream dataFile(outputPath + "/data.dat");
    if (!dataFile.is_open()) {
        std::cerr << "Error creating data file." << std::endl;
        return;
    }

    for (size_t i = 0; i < ts.size(); ++i) {
        dataFile << ts[i] << " " << ys[i] << std::endl;
    }

    dataFile.close();
}

void Output::plot() {
    createDataFile();

    std::string gnuplotCommand = "gnuplot -persist -e \"set terminal png size 800,600; "
                                 "set output '" + outputPath + "/plot.png'; "
                                 "plot '" + outputPath + "/data.dat' using 1:2 with lines\"";
    int result = system(gnuplotCommand.c_str());

    if (result == -1) {
        std::cerr << "Error executing GNUplot." << std::endl;
    }
}
