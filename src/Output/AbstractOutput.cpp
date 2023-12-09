#include "Output/AbstractOutput.h"

AbstractOutput::AbstractOutput(const std::vector<double>& ys, const std::vector<double>& ts, std::string id) //add outputpath
        : ys(ys), ts(ts), id(id) {}
