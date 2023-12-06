#include "FunctionComponent/FunctionComponent.h"

/**
 * @brief Generates a scalar component.
 * @param scalar The scalar value of the component.
 */
void FunctionComponent::generateScalarComponent(double scalar) {
    functionComponent = [scalar](double t, double y) {
        return scalar;
    };
}

/**
 * @brief Generates a polynomial term component.
 * @param scalar The coefficient of the term.
 * @param exponent The exponent of the term.
 */
void FunctionComponent::generateTermComponent(double scalar, double exponent) {
    functionComponent = [scalar, exponent](double t, double y) -> double {
        t = pow(t, exponent);
        t *= scalar;
        return t;
    };
}

/**
 * @brief Generates an exponential component.
 * @param base The base of the exponential component.
 */
void FunctionComponent::generateExpComponent(double base) {
    functionComponent = [base] (double t, double y) {
        return pow(base, t);
    };
}

/**
 * @brief Retrieves the function component.
 * @return The DoubleFunction representing the function component.
 */
DoubleFunction FunctionComponent::getFunction() const {
    return functionComponent;
}

/**
 * @brief Sums this component with another.
 * @param other Another FunctionComponent to sum with.
 * @return The resulting FunctionComponent after addition.
 */
FunctionComponent FunctionComponent::sum(const FunctionComponent &other) const {
    DoubleFunction f1 = this->functionComponent;
    DoubleFunction f2 = other.functionComponent;

    FunctionComponent result;
    result.functionComponent = [f1, f2](double t, double y) {
        return f1(t, y) + f2(t, y);
    };

    return result;
}

