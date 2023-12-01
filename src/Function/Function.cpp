#include "Function/Function.h"

void Function::addOperator(char sign) {
    operators.push_back(sign);
}

void Function::addComponent(FunctionComponent component) {
    components.push_back(component);
}

DoubleFunction Function::toDoubleFunction() const {
    DoubleFunction function;
    for (FunctionComponent component : components){
        for(char sign : operators) {
            if (sign == '+')
                function = components[0].getFunction();
        }
    }

    return function;
}