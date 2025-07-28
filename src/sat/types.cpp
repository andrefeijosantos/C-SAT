// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos <andre.santos1@ufv.br>
// Last updated: April 2025
//
// types.cpp
//      Implementation of basic CNF and clause utility functions, such as insertion,
//      unit clause detection, empty checks, and deep copying.
// ----------------------------------------------------------------------------------------

#include "types.h"



// @brief Adds a literal to a clause.
void add_literal(Clause& clause, Literal literal) {
    clause.insert(literal);
}

// @brief Adds a clause to a CNF formula.
void add_clause(CNF& formula, const Clause& clause) {
    formula.push_back(clause);
}

// @brief Checks if a clause is a unit clause (contains exactly one literal).
bool unit_clause(const Clause& clause) {
    return clause.size() == 1;
}

// @brief Checks if a formula has no clauses (i.e., is trivially SAT).
bool is_empty(const CNF& formula) {
    return formula.size() == 0;
}

// @brief Checks if a clause is empty (i.e., represents a contradiction).
bool is_empty(const Clause& clause) {
    return clause.size() == 0;
}

// @brief Finds a literal in a clause.
Clause::iterator in_clause(const Clause& clause, Literal literal) {
    return clause.find(literal);
}

// @brief Creates a deep copy of a CNF formula.
CNF copy_formula(const CNF& formula) {
    CNF copy;
    for (const Clause& clause : formula)
        add_clause(copy, clause);
    return copy;
}
