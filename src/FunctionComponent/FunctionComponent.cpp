#include "FunctionComponent/FunctionComponent.h"

void FunctionComponent::generateScalarComponent(double scalar) {
    functionComponent = [scalar](double* t, double* y) {
        return scalar;
    };
}

void FunctionComponent::generateTermComponent(double scalar, double exponent) {
     functionComponent = [scalar, exponent](double* t, double* y) -> double {
        *t = pow(*t, exponent);
        *t *= scalar;
        return *t;
    };
}

void FunctionComponent::generateExpComponent(double base) {
  functionComponent = [base] (double* t, double* y) {
        return pow(base, *t);
    };
}

DoubleFunction FunctionComponent::getFunction() {
    return functionComponent;
}
