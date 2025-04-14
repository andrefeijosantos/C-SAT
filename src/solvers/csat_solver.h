// ----------------------------------------------------------------------------------------
// Author: @andrefeijosantos
// Last updated: April 2025
//
// csat_solver.h
//      Definiton of CSATSolver class, an interface for all C-SAT solvers.
// ----------------------------------------------------------------------------------------

#ifndef CSAT_SOLVER_H
#define CSAT_SOLVER_H

#include "../sat/types.h"
#include "../sat/functions.h"


class CSATSolver {
    virtual Status solve(CNF&) = 0;
};

#endif