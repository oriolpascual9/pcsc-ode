#include "Reader/Reader.hh"
#include "FunctionComponent/FunctionComponent.hh"
#include <iostream>
#include <sstream>
#include <vector>
#include <regex>
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



Function Reader::read_function() {
  char instructions;
  std::string functionStr;
  
  std::cout << "Now introduce the function, do you want to know the instructions? (y/n): ";
  std::cin >> instructions;
  
  if (instructions == 'y' || instructions == 'Y') {
    std::cout << "Instructions:\n";
    std::cout << "Enter the function in the format: a*x^b + c*x^d + ...\n";
    std::cout << "For example, '3*x^2 - 1.5*x + 4'\n";
  }
  
  std::cout << "Enter your function: ";
  std::cin.ignore(); // Ignore leftover newline from previous input
  std::getline(std::cin, functionStr);
  
  return parse_function(functionStr);
}

Function Reader::parse_function_poly(const std::string& input) {
  Function function;
  std::istringstream iss(input);
  std::string token;
  
  // Regular expression for matching polynomial terms like "3*x^2"
  std::regex termPattern(R"(([-+]?[0-9]*\.?[0-9]+)\*x\^([-+]?[0-9]*\.?[0-9]+))");
  
  while (iss >> token) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      function.addOperator(token[0]);
    } else {
      FunctionComponent component;
      
      // Check if the token is a scalar
      try {
        double scalar = std::stod(token);
        component.generateScalarComponent(scalar);
      } catch (const std::invalid_argument&) {
        // Not a scalar, check if it is a term
        std::smatch matches;
        if (std::regex_match(token, matches, termPattern) && matches.size() == 3) {
          double scalar = std::stod(matches[1]);
          double exponent = std::stod(matches[2]);
          component.generateTermComponent(scalar, exponent);
        } else {
          // Handle other types of components or throw an error
          std::cerr << "Error: Unrecognized component format '" << token << "'\n";
        }
      }
      
      function.addComponent(component);
    }
  }
  
  return function;
}

/* --------------------------------------------------------------------------- */