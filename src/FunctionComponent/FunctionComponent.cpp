#include "FunctionComponent/FunctionComponent.h"

void FunctionComponent::generateScalarComponent(double scalar) {
    functionComponent = [scalar](double t, double y) {
        return scalar;
    };
}

void FunctionComponent::generateTermComponent(double scalar, double exponent) {
     functionComponent = [scalar, exponent](double t, double y) -> double {
        t = pow(t, exponent);
        t *= scalar;
        return t;
    };
}

void FunctionComponent::generateExpComponent(double base) {
  functionComponent = [base] (double t, double y) {
        return pow(base, t);
    };
}

DoubleFunction FunctionComponent::getFunction() const {
    return functionComponent;
}

FunctionComponent FunctionComponent::sum(const FunctionComponent &other) const {
  DoubleFunction f;
  DoubleFunction f1 = this->functionComponent;
  DoubleFunction f2 = other.functionComponent;

  f = [f1, f2](double t, double y) {
    return f1(t, y) + f2(t, y);
  };

  FunctionComponent result = FunctionComponent();
  result.functionComponent = f;

  return result;
}

FunctionComponent FunctionComponent::subtract(const FunctionComponent &other) const {
    DoubleFunction f;
    DoubleFunction f1 = this->functionComponent;
    DoubleFunction f2 = other.functionComponent;

    f = [f1, f2](double t, double y) {
        return f1(t, y) - f2(t, y);
    };

    FunctionComponent result = FunctionComponent();
    result.functionComponent = f;

    return result;
}

