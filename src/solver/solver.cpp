// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// solver.cpp
//      Implementation of CSATSolver methods used during SAT solving.
// ----------------------------------------------------------------------------------------

#include "solver.h"


// @brief Checks if a literal is a pure literal in the CNF formula.
bool CSATSolver::is_pure_literal(CNF& formula, Literal literal) {
    bool positive_pure = false,
         negative_pure = false;

    for (const Clause& clause : formula) {
        if (clause.find(literal) != clause.end())
            positive_pure = true;
        if (clause.find(neg literal) != clause.end())
            negative_pure = true;

        if (positive_pure & negative_pure)
            return false;
    }

    return positive_pure || negative_pure;
}