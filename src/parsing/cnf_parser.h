// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos <andre.santos1@ufv.br>
// Last updated: April 2025
//
// cnf_parser.h
//      Definiton of CNFParser class, a parser for DIMACS' CNF format.
// ----------------------------------------------------------------------------------------

#ifndef CNFPARSER_H
#define CNFPARSER_H

#include "../sat/types.h"
#include "../sat/functions.h"


class CNFParser {
    public:
        // Parse a .cnf file using DIMACS' syntax.
        // @param file Path to the file that has to be parsed.
        // @returns A pointer to the CNF formula parsed.
        CNF* parse(const char* file);
};

#endif