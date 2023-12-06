#include "Function/Function.h"
#include <iostream>

/**
 * @brief Adds an operator to the function.
 * @param sign The operator to be added (e.g., '+', '-').
 */
void Function::addOperator(char sign) {
    operators.push_back(sign);
}

/**
 * @brief Adds a component to the function.
 * @param component The FunctionComponent to be added.
 */
void Function::addComponent(FunctionComponent component) {
    components.push_back(component);
}

/**
 * @brief Converts the function to a DoubleFunction representation.
 * @return DoubleFunction representation of the function.
 * @throws Exception If the function has no components defined.
 */
DoubleFunction Function::toDoubleFunction() const {
    if (components.empty())
        throw Exception("Trying to convert the function but the function has no component defined");
    FunctionComponent currentComponent = components[0];
    for (int i = 1; i < components.size(); ++i) {
        currentComponent = currentComponent.sum(components[i]);
    }

    return currentComponent.getFunction();
}

/**
 * @brief Retrieves the operators of the function.
 * @return Vector of characters representing the operators.
 */
std::vector<char> Function::getOperators() {
    return operators;
}

/**
 * @brief Retrieves the components of the function.
 * @return Vector of FunctionComponent objects.
 */
std::vector<FunctionComponent> Function::getComponents() {
    return components;
}