// Author: @andrefeijosantos <andre.santos1@ufv.br>
// Last updated: July 2025
//
// parser.cpp
//      Implementation of CNFParser class methods, responsible for parsing
//      Boolean formulas written in DIMACS CNF format.
// ----------------------------------------------------------------------------------------

#include <fstream>
#include <iostream>

#include "parser.h"


// @brief Parse a .cnf file using DIMACS' syntax.
CNF CNFParser::parse(const char* file) {
    std::ifstream fin(file);

    if(!fin) {
        std::cerr << "\033[31m[ERROR]\033[0m Failed to open input file: \"" << file << "\"" << std::endl;
        std::cerr << "Please check that the path is correct and the file exists." << std::endl;
        std::cerr << "Aborting parser.\n" << std::endl;
        return {Clause()}; // unsat CNF.
    }

    std::string h1, h2; 
    int num_lits, num_clauses; 

    // Header parsing.
    fin >> h1 >> h2 >> num_lits >> num_clauses;

    // Clause parsing.
    Literal literal;
    CNF cnf;

    // Read each clause.
    for(int c = 0; c < num_clauses; c++) {
        Clause clause;
        while(true) {
            fin >> literal;

            // If 0 is found, the clause has ended.
            if(literal == 0) break;
            add_literal(clause, literal);
        }
        add_clause(cnf, clause);
    }

    return cnf;
}