#include "FunctionComponent/FunctionComponent.h"

void FunctionComponent::generateScalarComponent(double scalar) {
    functionComponent = [scalar](double t, double y) {
        return scalar;
    };
}

void FunctionComponent::generateTermComponent(double scalar, double exponent) {
    functionComponent = [scalar, exponent](double t, double y) -> double {
        y = pow(y, exponent);
        y *= scalar;
        return y;
    };
}

void FunctionComponent::generateExpComponent(double base) {
    functionComponent = [base] (double t, double y) {
        return pow(base, y);
    };
}

DoubleFunction FunctionComponent::getFunction() const {
    return functionComponent;
}

FunctionComponent FunctionComponent::sum(const FunctionComponent &other) const {
    DoubleFunction f1 = this->functionComponent;
    DoubleFunction f2 = other.functionComponent;

    FunctionComponent result;
    result.functionComponent = [f1, f2](double t, double y) {
        return f1(t, y) + f2(t, y);
    };

    return result;
}
