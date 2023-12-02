#include "Solver/DiscreteSolver.hh"

void DiscreteSolver::setFunction(Function function) {
    this->function = function;
}

void DiscreteSolver::setInitialY(double y) {
    this->y0 = y;
}

void DiscreteSolver::setDeltaT(double dt) {
    this->dt = dt;
}

void DiscreteSolver::setN(int n) {
    this->n = n;
}

