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

// Removes a clause from a formula.
void rmv_clause(CNF& formula, Clause* clause) {
    formula.erase(clause);
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

// Checks if a clause is an contradiction (i.e., an empty clause).
bool is_contradiction(Clause* clause) {
    return clause->size() == 0;
}

// Checks if a contradiction (i.e., an empty clause) is within a formula.
bool has_contradiction(CNF& formula) {
    for(Clause* clause : formula)
        if(is_contradiction(clause))
            return true;
    return false;
}

// Copies a clause to a new one.
// Please, note the high computational cost.
Clause* copy_clause(Clause* clause) {
    Clause* copy = new Clause;
    for(Literal l : *clause) 
        add_literal(copy, l);
    return copy;
}

// Copies a formula to a new one.
// Please, note the high computational cost.
CNF* copy_formula(CNF& formula) {
    CNF *copy = new CNF;
    for(Clause* clause : formula) {
        Clause *copied_clause = copy_clause(clause);
        add_clause(*copy, copied_clause);
    }
    return copy;
}