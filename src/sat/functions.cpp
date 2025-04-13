// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// functions.cpp
//      Definition of the references to functions.h functions.
// ----------------------------------------------------------------------------------------

#include "functions.h"


// Adds a new literal to a clause.
void add_literal(Clause* clause, Literal literal) {
    clause->insert(literal);
}

// Adds a new clause to the formula.
void add_clause(CNF& formula, Clause* clause) {
    formula.insert(clause);
}

// Checks if a clause is an unit clause.
bool unit_clause(Clause* clause) {
    return clause->size() == 1;
}

// Checks if a formula is an empty formula.
bool empty_formula(CNF& formula) {
    return formula.size() == 0;
}

// Checks if a literal is within a clause.
Clause::iterator in_clause(Clause* clause, Literal literal) {
    return clause->find(literal);
}
