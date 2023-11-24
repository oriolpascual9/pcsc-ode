#include "Reader.hh"
/* -------------------------------------------------------------------------- */

Problem Reader::read_problem(){
    std::cout << "Welcome to the Solver";
    int type = read_type_of_problem();
    Problem problem;
    switch (type)
    {
    case 1:
        problem = read_ODE_problem();
    default:
        break;
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

double* Reader::read_function(){
    char instructions;
    std::string function;
    std::cout << "Now introduce the function, do you want to know the instructions? (y/n)";
    std::cin >> instructions;

    if (instructions == 'y') {
        // TODO: Come up with an easy way to print the instructions
        std::cout << "This is supposed to be the instructions\n";
    }

    std::cout << "Introduce function: "
    std::cin >> function;

    return parse_function(function);
}



/* --------------------------------------------------------------------------- */


double* Reader::parse_function(std::string function){
    // Replace spaces to make parsing easier
    std::replace(function.begin(), function.end(), ' ', '');

    // Create a string stream from the equation
    std::istringstream iss(function);

    // Vector to store the split terms
    std::vector<std::string> terms;

    // Temporary variable to store each term
    std::string term;

    // Loop to extract terms
    while (std::getline(iss, term, '+')) {
        // Split by '-' within the term
        std::istringstream termStream(term);
        std::string subTerm;
        while (std::getline(termStream, subTerm, '-')) {
            terms.push_back(subTerm);
        }
    }

    return create_function(terms)
}

double* Reader::create_function(std::vector<std::string> terms) {

}

/* --------------------------------------------------------------------------- */


