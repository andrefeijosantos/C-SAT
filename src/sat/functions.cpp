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
