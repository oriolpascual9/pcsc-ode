#ifndef GRAPH_OUTPUT_H
#define GRAPH_OUTPUT_H

#include "AbstractOutput.h"
#include "ErrorHandler/ExceptionHandler.h"

class GraphOutput : public AbstractOutput {
private:
    std::string outputPath;

    void plot() const;

public:
    GraphOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath);
    void output() const override; // Implement the virtual function
};

#endif // GRAPH_OUTPUT_H

