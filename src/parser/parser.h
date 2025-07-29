// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos <andre.santos1@ufv.br>
// Last updated: July 2025
//
// parser.h
//      Definition of the CNFParser class, which parses Boolean formulas
//      in DIMACS CNF format into internal CNF representation.
// ----------------------------------------------------------------------------------------

#ifndef PARSER_H
#define PARSER_H

#include "../sat/types.h"


// @class CNFParser
// @brief Parses Boolean formulas in DIMACS CNF format.
class CNFParser {
    public:
        // @brief Parse a .cnf file using DIMACS' syntax.
        // 
        // @param file Path to the .cnf input file.
        // @return CNF The parsed formula as an internal CNF object.
        CNF* parse(const char* file);
};

#endif