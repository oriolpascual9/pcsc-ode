#include "Solver/ForwardEulerSolver.h"

double* ForwardEulerSolver::solve() const {
    double y = this->y0;
    double t = 0;

    for (int i = 0; i < this->n; ++i) {
        y += this->dt * this->f(t, y);
        t += this->dt;
    }

    return y;
}