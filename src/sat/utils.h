// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// utils.h
//      This file defines some utilities for C-SAT types.
// ----------------------------------------------------------------------------------------

#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "types.h"

// Converts a formula to string.
// @param formula The formula to be converted.
// @returns The string representation of the formula.
std::string to_string(CNF& formula);

// Converts a clause to string.
// @param clause The clause to be converted.
// @returns The string representation of the clause.
std::string to_string(Clause& clause);

#endif