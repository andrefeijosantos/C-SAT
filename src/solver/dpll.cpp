// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// dpll.cpp
//      Implements the DPLL algorithm for the CSATSolver class, including:
//          - unit propagation
//          - pure literal elimination
//          - recursive branching strategy
// ----------------------------------------------------------------------------------------

#include "../sat/utils.h"
#include "solver.h"


// @brief Applies unit propagation with a given literal on a CNF formula.
void CSATSolver::unit_propagation(CNF& cnf, Literal literal) {
    for (auto it = cnf.begin(); it != cnf.end(); ) {
        Clause& clause = *it;

        if (in_clause(clause, literal) != clause.end())
            it = cnf.erase(it);
        else {
            auto neg_it = in_clause(clause, neg literal);
            if (neg_it != clause.end()) clause.erase(neg_it);
            ++it;
        }
    }
}

// @brief Applies the DPLL algorithm to solve a CNF formula.
Status CSATSolver::dpll(CNF& cnf) {
    // Unit propagation.
    for(auto it = cnf.begin(); it != cnf.end(); ) {
        Clause& clause = *it;
        if (unit_clause(clause)) {
            Literal l = *clause.begin();
            unit_propagation(cnf, l);
            it = cnf.begin(); 
        } else it++;
    }

    // Pure literal elimination.
    std::set<Literal> literals;
    for (const Clause& clause : cnf)
        for (const Literal& literal : clause)
            literals.insert(literal);

    for (Literal literal : literals)
        if (is_pure_literal(cnf, literal)) {
            for (auto it = cnf.begin(); it != cnf.end(); ) {
                Clause& clause = *it;
                
                if (in_clause(clause, literal) != clause.end()) {
                    if (unit_clause(clause)) it = cnf.erase(it);
                    else {
                        clause.erase(literal);
                        it++;
                    }
                } else it++;
            }
            literals.erase(literal);
        }


    // Stopping conditions.
    // Satisfiable if cnf is empty.
    if(is_empty(cnf))
        return sat;

    // Unsatisfiable if any clause is empty.
    for(const Clause& clause : cnf)
        if(is_empty(clause))
            return unsat;

    // Branching procedure.
    Literal l = DPLL_choose_literal(cnf);

    CNF left = copy_formula(cnf);
    Clause l_clause = {l};
    add_clause(left, l_clause);

    CNF right = copy_formula(cnf);
    Clause neg_l_clause = {neg l};
    add_clause(right, neg_l_clause);

    return dpll(left) || dpll(right);
}

// @brief Chooses a literal for branching in the DPLL algorithm.
Literal CSATSolver::DPLL_choose_literal(CNF& cnf) {
    return (*(*cnf.begin()).begin());
}