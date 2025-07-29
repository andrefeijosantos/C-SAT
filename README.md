# C-SAT

**C-SAT** is a simple SAT solver written in modern C++. It currently supports parsing formulas in the DIMACS CNF format and solving them using the classic DPLL algorithm.

This project is primarily intended as a learning tool, but its modular design makes it easy to extend and experiment with advanced techniques in satisfiability solving.

## Version and Features

### Version 1.0.0

- ```DIMACS CNF parser``` added;
- ```DPLL solving algorithm``` added. 

## Getting Started

### Prerequisites

- A C++ compiler supporting C++11 or newer (e.g., `g++`, `clang++`)
- Basic knowledge of compiling C++ from the command line

### Building

> **Note:** This project does not yet use a build system like CMake.

To compile manually:

```sh
g++ -O2 src/main.cpp src/solver/solver.cpp src/solver/dpll.cpp src/solver/cdcl.cpp  src/sat/types.cpp src/sat/utils.cpp  src/parser/parser.cpp -o csat
```

### Running C-SAT
Once compiled, you can run C-SAT on any DIMACS CNF file:

```sh
./csat examples/tiny1.cnf DPLL        # Expected result: UNSAT
```
If no algorithm is specified, C-SAT defaults to **DPLL**. CDCL is included in the codebase but not fully supported yet.

### Examples
A few test cases are included under the examples/ directory. These are helpful for testing and experimentation with small formulas.

## Next Steps
- CDCL implementation;

- Heuristic improvements;

- Tseytin transformation and support for richer input formats

- CMake build support

- Benchmark suite

## Author
Developed by @andrefeijosantos

## License

The C-SAT solver project is released under the terms of the MIT License.