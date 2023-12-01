#include "Reader/Reader.hh"

/* -------------------------------------------------------------------------- */

Problem& Reader::read_problem(){
    std::cout << "Welcome to the Solver";
    int type = read_type_of_problem();
    switch (type)
    {
    case 1:
        Problem_ODE problem = read_ODE_Problem();
        return problem;
    }
}

int Reader::read_type_of_problem() {
    int type;
    std::cout << "Select type of problem:\n";
    std::cout << "  1. ODE's\n";
    std::cin >> type;
    
    // Min condition
    assert(type > 0);
    // Max condition will depend on the number of problems
    assert(type <= 1);
    
    return type;
}

/* --------------------------------------------------------------------------- */

Function Reader::read_function(){
    char instructions;
    std::string functionStr;
    std::cout << "Now introduce the function, do you want to know the instructions? (y/n)";
    std::cin >> instructions;

    if (instructions == 'y') {
        // TODO: Come up with an easy way to print the instructions
        std::cout << "This is supposed to be the instructions\n";
    }

    // TODO: Readin function method
    // TODO: Read Function Component one by one and append them to Function class

    Function function;
    return function;
}

/* --------------------------------------------------------------------------- */