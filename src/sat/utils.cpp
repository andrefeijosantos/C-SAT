// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// utils.cpp
//      Implementation of utility functions for C-SAT. Provides functions to convert
//      clauses and CNF formulas into human-readable string representations.
// ----------------------------------------------------------------------------------------

#include <string>

#include "utils.h"


// @brief Converts a CNF formula to a string representation.
std::string to_string(const Clause& clause) {
    int lcnt = 0;

    std::string str = "(";
    for(Literal literal : clause) {
        if(literal < 0) str += "~";
        str += "p" + std::to_string(affirm(literal));

        if(++lcnt < clause.size())
            str += " v ";
    }
    str += ")";
    return str;
}

// @brief Converts a clause to a string representation.
std::string to_string(const CNF& formula) {
    int ccnt = 0;
    
    std::string str = "(";
    for(const Clause& clause : formula) {
        str += to_string(clause);
        if(++ccnt < formula.size())
            str += " ^ ";
    }
    str += ")";
    return str;
}