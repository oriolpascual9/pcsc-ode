#include "Reader/Reader.hh"
#include "FunctionComponent/FunctionComponent.hh"
#include "ExceptionHandler.h"
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
      Function polyComponent = parse_function_poly(functionStr);
      // Logic to combine `polyComponent` with `function`
      // This depends on how you want to combine functions
    } else if (functionType == "exp") {
      Function expComponent = parse_function_exp(functionStr);
      // Logic to combine `expComponent` with `function`
      // This depends on how you want to combine functions
    } else {
      std::cerr << "Error: Unrecognized function type '" << functionType << "'\n";
      // Optionally, continue to next iteration or break the loop
    }
    
    std::cout << "Do you want to add another component? (y/n): ";
    std::cin >> continueParsing;
  }
  
  return function;
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

Function Reader::parse_function_exp(const std::string& input) {
  Function function;
  std::istringstream iss(input);
  std::string token;
  
  // Regular expression for matching exponential terms like "2.5^y"
  std::regex expPattern(R"(([-+]?[0-9]*\.?[0-9]+)\^y)");
  
  while (iss >> token) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      function.addOperator(token[0]);
    } else {
      FunctionComponent component;
      std::smatch matches;
      
      if (std::regex_match(token, matches, expPattern) && matches.size() == 2) {
        double base = std::stod(matches[1]);
        // Assuming generateExpComponent creates an exponential component of type base^y
        component.generateExpComponent(base);
      } else {
        // Handle other types of components or throw an error
        std::cerr << "Error: Unrecognized component format '" << token << "'\n";
      }
      
      function.addComponent(component);
    }
  }
  
  return function;
}
/* --------------------------------------------------------------------------- */