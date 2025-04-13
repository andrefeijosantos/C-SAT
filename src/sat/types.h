// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos <andre.santos1@ufv.br>
// Last updated: April 2025
//
// types.h
//      Definition of Literal; Clause and CNF, which aliases for int; set<int> and 
//   set<set<int>>, respectively.
// ----------------------------------------------------------------------------------------

#ifndef CLAUSE_H
#define CLAUSE_H

#include <set>


// Formula assignment: sat or unsat.
#define Status bool
#define sat true
#define unsat false

// Representation of a formula.
#define Literal int
#define Clause std::set<Literal>
#define CNF std::set<Clause*>


// Logical negation
#define neg -1*

// afirm neg l = l
// afirm     l = l
#define afirm abs

#endif