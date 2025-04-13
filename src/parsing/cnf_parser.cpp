// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos <andre.santos1@ufv.br>
// Last updated: April 2025
//
// cnf_parser.cpp
//      Definition of the references to CNFParser methods.
// ----------------------------------------------------------------------------------------

#include <fstream>
#include <iostream>

#include "cnf_parser.h"


// Parse a .cnf file using DIMACS' syntax.
CNF* CNFParser::parse(const char* file) {
    std::ifstream fin(file);

    if(!fin) {
        std::cout << "No file \"" << file << "\" found. \nAborting...\n";
        return nullptr;
    }

    std::string h1, h2; 
    int num_lits, num_clauses; 

    // Header parsing.
    fin >> h1 >> h2 >> num_lits >> num_clauses;

    // Clause parsing.
    Literal literal;
    CNF* cnf = new CNF;

    // Read each clause.
    for(int c = 0; c < num_clauses; c++) {
        Clause* clause = new Clause;
        while(true) {
            fin >> literal;

            // If 0 is found, the clause has ended.
            if(literal == 0) break;
            add_literal(clause, literal);
        }
        add_clause(*cnf, clause);
    }

    return cnf;
}