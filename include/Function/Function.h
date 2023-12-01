#ifndef PCSC_ODE_FUNCTION_H
#define PCSC_ODE_FUNCTION_H

#include<vector>

#include "FunctionComponent/FunctionComponent.h"

class Function {
private:
    std::vector<FunctionComponent> components;
    std::vector<char> operators;

public:
    Function(){};
    void addOperator(char sign);
    void addComponent(FunctionComponent component);
    DoubleFunction toDoubleFunction();

};


#endif //PCSC_ODE_FUNCTION_H
