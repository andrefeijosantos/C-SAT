// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// utils.h
//      Utility functions for converting CNF formulas and clauses into readable string
//      representations. These are useful for debugging, logging, and visualization.
// ----------------------------------------------------------------------------------------

#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "types.h"

// @brief Converts a CNF formula to a string representation.
// @param formula The CNF formula to convert.
// @return A human-readable string version of the formula.
std::string to_string(const CNF& formula);

// @brief Converts a clause to a string representation.
// @param clause The clause to convert.
// @return A human-readable string version of the clause.
std::string to_string(const Clause& clause);

#endif