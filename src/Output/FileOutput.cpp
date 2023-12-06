#include "Output/FileOutput.h"
#include <fstream>
#include <iostream>

/**
 * @brief Constructor for FileOutput.
 * @param ys Vector of computed values.
 * @param ts Vector of time or independent variable values.
 * @param outputPath Path for the output file.
 *
 * Initializes the FileOutput object with the provided vectors and output path.
 */
FileOutput::FileOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath)
        : AbstractOutput(ys, ts), outputPath(outputPath) {}

/**
 * @brief Creates a data file at the specified output path.
 * @throws Exception If the file cannot be created.
 *
 * Writes the time and computed values to a data file in a structured format.
 */
void FileOutput::createDataFile() const {
    if (!std::filesystem::exists(outputPath)) {
        throw Exception("Output path does not exist");
    }

    std::ofstream dataFile(outputPath + "/data.dat");
    if (!dataFile.is_open()) {
        throw Exception("Error creating data file.");
    }

    for (size_t i = 0; i < ts.size(); ++i) {
        dataFile << ts[i] << " " << ys[i] << std::endl;
    }

    dataFile.close();
}

/**
 * @brief Outputs the data to a file.
 *
 * Calls createDataFile() to output the computed values to a file. Catches and
 * reports any exceptions encountered during file creation.
 */
void FileOutput::output() const {
        createDataFile();
}