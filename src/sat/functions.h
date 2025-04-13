// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos <andre.santos1@ufv.br>
// Last updated: April 2025
//
// functions.h
//      Definition of functions applied over Formulas, Clauses and Literals.
// ----------------------------------------------------------------------------------------

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "types.h"


// Adds a new literal to a clause.
// @param clause A pointer to the clause where the literal will be inserted.
// @param literal The literal to add.
void add_literal(Clause*, Literal);

// Adds a new clause to the formula.
// @param formula The formula where the new clause will be inserted.
// @param clause A pointer to the clause to be added.
void add_clause(CNF&, Clause*);

// Checks if a clause is an unit clause.
// @param clause A pointer to a clause.
// @return true, if it's a unit clause; false, otherwise.
bool unit_clause(Clause*);

// Checks if a formula is an empty formula.
// @param formula The formula to be checked.
bool empty_formula(CNF&);

// Checks if a literal is within a clause.
// @param clause The clause to find the literal.
// @param literal The literal to find.
// @returns A iterator to the literal, if it was found; clause.end(), otherwise.
Clause::iterator in_clause(Clause*, Literal);

#endif