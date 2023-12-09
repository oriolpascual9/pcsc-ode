#include "Output/FileOutput.h"

FileOutput::FileOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath, std::string id)
        : AbstractOutput(ys, ts, id), outputPath(outputPath) {}

void FileOutput::createDataFile() const {
    if (!std::filesystem::exists(outputPath)) {
        throw Exception("Output path does not exist");
    }

    std::ofstream dataFile(outputPath + '/' + id + ".dat");
    if (!dataFile.is_open()) {
        throw Exception("Error creating data file.");
    }

    for (size_t i = 0; i < ts.size(); ++i) {
        dataFile << ts[i] << " " << ys[i] << std::endl;
    }

    dataFile.close();
}

void FileOutput::output() const {
        createDataFile();
}