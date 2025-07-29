// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// cdcl.cpp (In development)
//      Implements the CDCL algorithm for the CSATSolver class.
// ----------------------------------------------------------------------------------------

#include <iostream>

#include "solver.h"


bool CSATSolver::cdcl(CNF& cnf) {
    std::cerr << "[ \033[33mWARNING\033[0m ] CDCL algorithm is not yet implemented." << std::endl;
    std::cerr << "Retuning unsat as default value..." << std::endl;
    return unsat; // Default return value for unimplemented algorithm.
}