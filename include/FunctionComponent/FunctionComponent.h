#ifndef PCSC_ODE_FUNCTIONCOMPONENT_H
#define PCSC_ODE_FUNCTIONCOMPONENT_H

#include <cmath>
#include <functional>

using DoubleFunction = std::function<double(double, double)>;

class FunctionComponent {
private:
    DoubleFunction functionComponent;

public:
    FunctionComponent(){}
    void generateScalarComponent(double scalar);
    void generateTermComponent(double scalar, double exponent);
    void generateExpComponent(double base);
    DoubleFunction getFunction() const;
    DoubleFunction sum(const FunctionComponent &other) const;
};


#endif //PCSC_ODE_FUNCTIONCOMPONENT_H
