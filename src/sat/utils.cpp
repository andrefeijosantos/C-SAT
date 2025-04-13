// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// utils.cpp
//      Definition of the references to utils.h functions.
// ----------------------------------------------------------------------------------------

#include <string>

#include "utils.h"


// Converts a formula to string.
std::string clause2str(Clause& clause) {
    int lcnt = 0;

    std::string str = "(";
    for(Literal literal : clause) {
        if(literal < 0) str += "~";
        str += "p" + std::to_string(afirm(literal));

        if(++lcnt < clause.size())
            str += " v ";
    }
    str += ")";
    return str;
}

// Converts a clause to string.
std::string cnf2str(CNF& formula) {
    int ccnt = 0;
    
    std::string str = "(";
    for(Clause* clause : formula) {
        str += clause2str(*clause);
        if(++ccnt < formula.size())
            str += " ^ ";
    }
    str += ")";
    return str;
}