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
// @param clause The clause where the literal will be inserted.
// @param literal The literal to add.
void add_literal(Clause*, Literal);

// Adds a new clause to the formula.
// @param formula The formula where the new clause will be inserted.
// @return A pointer to the new clause.
void add_clause(CNF&, Clause*);

#endif