#include "OutputHandler/OutputHandler.h"

OutputHandler::OutputHandler(int outputType, const std::pair<std::vector<double>, std::vector<double>>& solution, const std::string& outputPath, const std::string& ID) {
    // create the directory if it doesn't exist
    if (!std::filesystem::exists(outputPath)) {
        std::filesystem::create_directories(outputPath);
    }

    if (outputType == 1) {
        outputPtr = std::make_unique<GraphOutput>(solution.second, solution.first, outputPath, ID);
    } else if (outputType == 2) {
        outputPtr = std::make_unique<FileOutput>(solution.second, solution.first, outputPath, ID);
    } else {
        throw std::invalid_argument("Invalid output type");
    }
}

void OutputHandler::generateOutput() {
    if (outputPtr) {
        outputPtr->output();
    }
}
