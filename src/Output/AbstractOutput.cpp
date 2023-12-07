#include "Output/AbstractOutput.h"

/**
 * @brief Constructor for AbstractOutput.
 * @param ys The vector of computed values.
 * @param ts The vector of time or independent variable values.
 *
 * Initializes the AbstractOutput object with the provided vectors of computed values
 * and their corresponding times or independent variable values.
 */
AbstractOutput::AbstractOutput(const std::vector<double>& ys, const std::vector<double>& ts, std::string id) //add outputpath
        : ys(ys), ts(ts), id(id) {}
