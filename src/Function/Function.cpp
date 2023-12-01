#include "Function/Function.h"

void Function::addOperator(char sign) {
    operators.push_back(sign);
}

void Function::addComponent(FunctionComponent component) {
    components.push_back(component);
}

DoubleFunction Function::toDoubleFunction() const {
    FunctionComponent currentComponent = FunctionComponent();
    for (FunctionComponent component : components){
        for(char sign : operators) {
            if (sign == '+')
                currentComponent = currentComponent.sum(component);
            else
                currentComponent = currentComponent.subtract(component);
        }
    }

    return currentComponent.getFunction();
}