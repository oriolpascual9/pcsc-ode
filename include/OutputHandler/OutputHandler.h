#ifndef OUTPUT_HANDLER_H
#define OUTPUT_HANDLER_H

#include "Output/FileOutput.h"
#include "Output/GraphOutput.h"
#include <memory> // For std::unique_ptr

class OutputHandler {
public:
    OutputHandler(int outputType, const std::pair<std::vector<double>, std::vector<double>>& solution, const std::string& outputPath, const std::string& ID);

    void generateOutput();

private:
    std::unique_ptr<AbstractOutput> outputPtr;
};

#endif // OUTPUT_HANDLER_H
