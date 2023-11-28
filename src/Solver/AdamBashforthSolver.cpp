#include "Solver/AdamBashforthSolver.h"

double* AdamBashforthSolver::solve() const {
    std::vector<double> ys(4, this->y0); // Initialize with size 4 and initial value y0
    double y = this->y0;
    double t = 0;

    // Compute the initial steps using a smaller solver instance
    for (int i = 0; i < std::min(this->n, 4); ++i) {
        DiscreteSolver <double> initialSolver(this->f, this->y0, this->dt, i + 1);
        ys[i] = this->initialMethod(initialSolver);
    }

    for (int i = 4; i < this->n; ++i) {
        y = ys[3] + this->dt * (55 * this->f(t, ys[3]) - 59 * this->f(t - this->dt, ys[2]) + 37 * this->f(t - 2 * this->dt, ys[1]) - 9 * this->f(t - 3 * this->dt, ys[0])) / 24;
        t += this->dt;

        // Update previous y values
        for (int j = 3; j > 0; --j) {
            ys[j] = ys[j - 1];
        }
        ys[0] = y;
    }

    return y;
}