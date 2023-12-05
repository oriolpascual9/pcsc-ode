#ifndef FILE_OUTPUT_H
#define FILE_OUTPUT_H

#include "AbstractOutput.h"

class FileOutput : public AbstractOutput {
private:
    std::string outputPath;

    void createDataFile() const;

public:
    FileOutput(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath);
    void output() const override; // Implement the virtual function
};

#endif // FILE_OUTPUT_H

