// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos <andre.santos1@ufv.br>
// Last updated: April 2025
//
// types.h
//      Definitions of core SAT structures:
//        - Literal:    Integer representing a Boolean variable (positive or negative).
//        - Clause:     Set of literals (disjunction).
//        - CNF:        List of clauses (conjunction of disjunctions).
//      Also includes utility functions for CNF manipulation.
// ----------------------------------------------------------------------------------------

#ifndef TYPES_H
#define TYPES_H

#include <set>
#include <list>


// Formula assignment: sat or unsat.
#define Status bool
#define sat true
#define unsat false

// Representation of a formula.
#define Literal int                 // @note Positive = variable, Negative = negation.
#define Clause std::set<Literal>
#define CNF std::list<Clause>


// Logical negation
#define neg -1*

// affirm neg l = l
// affirm     l = l
#define affirm abs


// @brief Adds a literal to a clause.
// @param clause Clause to which the literal will be added.
// @param literal The literal to add.
void add_literal(Clause& clause, Literal literal);

// @brief Adds a clause to a CNF formula.
// @param formula The formula to which the clause will be added.
// @param clause The clause to add.
void add_clause(CNF& formula, const Clause& clause);

// @brief Checks if a clause is a unit clause (contains exactly one literal).
// @param clause The clause to check.
// @return True if the clause is a unit clause, false otherwise.
bool unit_clause(const Clause& clause);

// @brief Checks if a formula has no clauses (i.e., is trivially SAT).
// @param formula The CNF formula to check.
// @return True if the formula is empty, false otherwise.
bool is_empty(const CNF& formula);

// @brief Checks if a clause is empty (i.e., represents a contradiction).
// @param clause The clause to check.
// @return True if the clause is empty, false otherwise.
bool is_empty(const Clause& clause);

// @brief Finds a literal in a clause.
// @return An iterator to the literal if found, or clause.end() otherwise.
Clause::iterator in_clause(const Clause& clause, Literal literal);

// @brief Creates a deep copy of a CNF formula.
// @param formula The CNF formula to copy.
// @return A new CNF object that is a copy of the input formula.
CNF copy_formula(const CNF& formula);

#endif