#ifndef OUTPUT_HH
#define OUTPUT_HH

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Output {
private:
    std::vector<double> ys;
    std::vector<double> ts;
    std::string outputPath;

    void createDataFile() const;

public:
    Output(const std::vector<double>& ys, const std::vector<double>& ts, const std::string& outputPath);
    void plot();
};

#endif // OUTPUT_HH
