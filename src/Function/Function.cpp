#include "Function/Function.h"
#include <iostream>

void Function::addOperator(char sign) {
    operators.push_back(sign);
}

void Function::addComponent(FunctionComponent component) {
    components.push_back(component);
}

DoubleFunction Function::toDoubleFunction() const {
    if (components.size() == 0)
        throw Exception("Trying to convert the function but the function has no component defined");

    FunctionComponent currentComponent = components[0];
    for (int i=1; i < components.size(); i++){
            std::cout << operators[i-1] << '\n';
            if (operators[i-1] == '+')
                currentComponent = currentComponent.sum(components[i]);
            else
                currentComponent = currentComponent.subtract(components[i]);
    }

    return currentComponent.getFunction();
}

std::vector<char> Function::getOperators() {
    return operators;
}

std::vector<FunctionComponent> Function::getComponents() {
    return components;
}