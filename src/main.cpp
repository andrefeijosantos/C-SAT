// ----------------------------------------------------------------------------------------
// C-SAT: A Minimal C++ SAT Solver
// File: main.cpp
//
// Entry point for the C-SAT solver.
// Handles:
//   - Input parsing
//   - Algorithm selection (DPLL/CDCL)
//   - Formula parsing from DIMACS file
//   - Execution and reporting of solving status
//
// Usage:
//   g++ -O2 main.cpp solver/utils.cpp solver/dpll.cpp solver/cdcl.cpp sat/types.cpp sat/utils.cpp parser/parser.cpp
//   ./csat <input_file.cnf> <algorithm (DPLL/CDCL)>
//
// author: @andrefeijosantos
// Repository: https://github.com/andrefeijosantos/C-SAT
// Version: 1.0.0
// Last updated: July 2025
// ----------------------------------------------------------------------------------------

#include <iostream>
#include <chrono>

#include "csat.h"

// Version information
#define VERSION "1.0.0"

// Color codes for terminal output
#define RESET "\033[0m"
#define RED(text) "\033[31m" << text << RESET
#define YELLOW(text) "\033[33m" << text <<  RESET
#define GREEN(text) "\033[32m" << text << RESET

// Function prototyping.
void print_header();


int main(int argc, char* argv[]) {
    print_header();

    // Check if input file is provided.
    if (argc < 2) {
        std::cerr << "[ " << RED("ERROR") << " ] No input file provided." << std::endl;
        std::cerr << "Usage: " << argv[0] << " <input_file> <algorithm (DPLL/CDCL)>" << std::endl;
        return 1;
    }

    // Check if algorithm is specified, default to DPLL if not.
    Algorithm algorithm = Algorithm::DPLL;
    std::string algorithm_str;
    if(argc < 3) {
        std::cerr << "[ " << YELLOW("WARNING") << " ] No algorithm specified. Using default (DPLL)." << std::endl;
        algorithm_str = "DPLL";
    } else {
        if (std::string(argv[2]) == "DPLL") {
            algorithm = Algorithm::DPLL;
            algorithm_str = "DPLL";
        }
        else if (std::string(argv[2]) == "CDCL") {
            algorithm = Algorithm::CDCL;
            algorithm_str = "CDCL";
        }
        else {
            std::cerr << "[ " << RED("ERROR") << " ] Invalid algorithm specified." << std::endl;
            std::cerr << "Usage: " << argv[0] << " <input_file> <algorithm (DPLL/CDCL)>" << std::endl;
            return 1;
        }
    }

    // Read the input file and parse the CNF formula.
    const char* input_file = argv[1];
    std::cout << "[1/4] Reading input file: " << input_file << std::endl;

    CNF* formula = CNFParser().parse(input_file);
    if(formula == nullptr) {
        std::cerr << "[ " << RED("ERROR") << " ] Failed to open input file: \"" << argv[1] << "\"" << std::endl;
        std::cerr << "Please check that the path is correct and the file exists." << std::endl;
        return 1;
    }

    std::cout << "[2/4] Formula parsed successfully." << std::endl;

    // Initialize the solver and solve the CNF formula using the specified algorithm.
    CSATSolver solver;
    std::cout << "[3/4] Solving with " << algorithm_str << " algorithm..." << std::endl;

    auto start_time = std::chrono::high_resolution_clock::now();

    Status result = solver.solve(*formula, algorithm);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);


    // Print the result of the solving process.
    std::cout << "[4/4] Solving completed. Result: ";
    if (result == sat) 
        std::cout << GREEN("SATISFIABLE") << std::endl; 
    else std::cout << RED("UNSATISFIABLE") << std::endl;

    std::cout << "      Execution time: " << duration.count() << " ms" << std::endl;

    // Free the allocated CNF object to gracefully finish the program.
    delete formula; 

    return 0;
}

// @brief Prints the header information for the C-SAT solver.
void print_header() {
    std::cout << "C-SAT Solver | version " << VERSION << std::endl;
    std::cout << "author: @andrefeijosantos (https://github.com/andrefeijosantos/C-SAT)\n" << std::endl;
}