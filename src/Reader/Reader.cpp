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

Function Reader::choose_parse_function() {
    Function function;
    std::string functionType;
    std::string functionStr;
    char continueParsing = 'y';

    while (continueParsing == 'y' || continueParsing == 'Y') {
        std::cout << "Enter the type of function component (poly/exp): ";
        std::cin >> functionType;

        std::cout << "Enter the function component: ";
        std::cin.ignore(); // Ignore leftover newline from previous input
        std::getline(std::cin, functionStr);

        if (functionType == "poly") {
            parse_function_poly(function, functionStr);
        } else if (functionType == "exp") {
            parse_function_exp(function, functionStr);
        } else {
            throw Exception("Error: Unrecognized function type '" + functionType + "'");
        }

        std::cout << "Do you want to add another component? (y/n): \n";
        std::cin >> continueParsing;
    }

    return function;
}


void Reader::parse_function_poly(Function& function, const std::string& input) {
  std::istringstream iss(input);
  std::string token;
  
  // Regular expression for matching polynomial terms like "3*x^2"
  std::regex termPattern(R"(([-+]?[0-9]*\.?[0-9]+)\*y\^([-+]?[0-9]*\.?[0-9]+))");
  
  while (iss >> token) {
    if (token[0] == '+' || token[0] == '-') { // for future expansion: || token == "*" || token == "/"
      function.addOperator(token[0]);
    }
      FunctionComponent component;
      
      // Check if the token is a scalar
        size_t idx;
        double scalar = std::stod(token, &idx);

        if (idx == token.size()) {
            component.generateScalarComponent(scalar);
        }
        else {
        // Not a scalar, check if it is a term
        std::smatch matches;
        if (std::regex_match(token, matches, termPattern) && matches.size() == 3) {
            double scalar = std::stod(matches[1]);
          double exponent = std::stod(matches[2]);
          component.generateTermComponent(scalar, exponent);
        } else {
            if (!std::regex_match(token, matches, termPattern) || matches.size() != 3) {
                throw Exception("Error: Unrecognized component format '" + token + "'");
            }
        }
      }
      
      function.addComponent(component);
    }
}

void Reader::parse_function_exp(Function& function, const std::string& input) {
  std::istringstream iss(input);
  std::string token;
  
  // Regular expression for matching exponential terms like "2.5^y"
  std::regex expPattern(R"(([-+]?[0-9]*\.?[0-9]+)\^y)");
  
  while (iss >> token) {
    if (token[0] == '+' || token[0] == '-' ) { // for future expansion: || token == "*" || token == "/"
      function.addOperator(token[0]);
    }
      FunctionComponent component;
      std::smatch matches;

      if (std::regex_match(token, matches, expPattern) && matches.size() == 2) {
        double base = std::stod(matches[1]);
        // Assuming generateExpComponent creates an exponential component of type base^y
        component.generateExpComponent(base);
      } else {
          if (!std::regex_match(token, matches, expPattern) || matches.size() != 2) {
              throw Exception("Error: Unrecognized component format '" + token + "'");
          }
      }

      function.addComponent(component);
    }
}
/* --------------------------------------------------------------------------- */