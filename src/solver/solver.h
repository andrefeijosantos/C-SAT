// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// solver.h
//      Definition of the CSATSolver class, which provides an interface for
//      C-SAT solving algorithms (DPLL, CDCL).
// ----------------------------------------------------------------------------------------

#ifndef CSAT_SOLVER_H
#define CSAT_SOLVER_H

#include "../sat/types.h"

enum Algorithm {
    DPLL,
    CDCL
};


// @class CSATSolver
// @brief Interface for solving CNF formulas using DPLL or CDCL algorithms.
class CSATSolver {
    private:
        // @brief Applies unit propagation with a given literal on a CNF formula.
        // @param cnf The CNF formula to be modified.
        // @param literal The literal to propagate.
        void unit_propagation(CNF& cnf, Literal literal);

        // @brief Chooses a literal for branching in the DPLL algorithm.
        // @param cnf The CNF formula to analyze.
        // @return A literal chosen for branching.
        Literal DPLL_choose_literal(CNF& cnf);

        // @brief Checks if a literal is a pure literal in the CNF formula.
        // @param formula The CNF formula to check.
        // @param literal The literal to check.
        // @return True if the literal is pure, false otherwise.
        bool is_pure_literal(CNF& formula, Literal literal);
        
        // @brief Applies the DPLL algorithm to solve a CNF formula.
        // @param cnf The CNF formula to solve.
        // @return The status of the solving process (sat, unsat).
        Status dpll(CNF& cnf);
        
        // TODO: To be implemented in future versions.
        // @brief Applies the CDCL algorithm to solve a CNF formula.
        // @param cnf The CNF formula to solve.
        // @return The status of the solving process (sat, unsat).
        Status cdcl(CNF& cnf);

    public:
        // @brief Solves a CNF formula using the specified algorithm.
        // @param cnf The CNF formula to solve.
        // @param algorithm The algorithm to use ("DPLL" or "CDCL").
        // @return The status of the solving process (sat, unsat).
        Status solve(CNF& cnf, Algorithm algorithm) {
            if(algorithm == Algorithm::DPLL)
                return dpll(cnf);
            else if(algorithm == Algorithm::CDCL)
                return cdcl(cnf);
            else
                return unsat; // Invalid algorithm
        }
};

#endif