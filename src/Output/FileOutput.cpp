#include "FileOutput.h"
#include <fstream>
#include <iostream>

FileOutput::FileOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath)
        : AbstractOutput(ys, ts), outputPath(outputPath) {}

void FileOutput::createDataFile() const {
    std::ofstream dataFile(outputPath + "/data.dat");
    if (!dataFile.is_open()) {
        throw Exception("Error creating data file.");
    }

    for (size_t i = 0; i < ts.size(); ++i) {
        dataFile << ts[i] << " " << ys[i] << std::endl;
    }

    dataFile.close();
}

void FileOutput::output() const {
    try {
        createDataFile();
    } catch (const Exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
