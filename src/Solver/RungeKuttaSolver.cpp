#include "Solver/RungeKuttaSolver.h"

double* RungeKuttaSolver::solve() const {
    double y = this->y0;
    double t = 0;

    for (int i = 0; i < this->n; ++i) {
        double k1 = this->dt * this->f(t, y);
        double k2 = this->dt * this->f(t + this->dt / 2, y + k1 / 2);
        double k3 = this->dt * this->f(t + this->dt / 2, y + k2 / 2);
        double k4 = this->dt * this->f(t + this->dt, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        t += this->dt;
    }

    return y;
}