#include <iostream>
#include "Reader/Reader_ODE.hh"
#include "Reader/Reader.hh"
#include "ErrorHandler/ExceptionHandler.h" // Include your custom exception header

int main() {
    try {
        // Assuming Reader is now a concrete class with all virtual functions implemented
        std::string outputPath;
        Reader_ODE reader;
        Problem& base_problem = reader.read_problem(); // Read the problem as a base class reference
        // Dynamic cast to convert base class reference to derived class reference
        Problem_ODE& problem = dynamic_cast<Problem_ODE&>(base_problem);
        DiscreteSolver& solver = reader.read_discrete_solver(); // Read the solver
        std::cout << "Problem initialized and solver selected." << std::endl;
        int typeOutput = reader.read_type_of_output();
        problem.solve(solver);
        std::pair solution = problem.getSolution();
        std::string ID =  problem.getID();


    } catch (const Exception& e) {
        // Catching your custom exception
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}