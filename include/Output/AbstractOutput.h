#ifndef ABSTRACT_OUTPUT_H
#define ABSTRACT_OUTPUT_H

#include <vector>
#include <string>

class AbstractOutput {
protected:
    std::vector<double> ys;
    std::vector<double> ts;

public:
    AbstractOutput(const std::vector<double>& ys, const std::vector<double>& ts);
    virtual ~AbstractOutput() = default;

    virtual void output() const = 0; // Pure virtual function
};

#endif // ABSTRACT_OUTPUT_H

