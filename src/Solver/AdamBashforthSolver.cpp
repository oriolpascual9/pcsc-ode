#include "Solver/AdamBashforthSolver.h"
#include <utility> // for std::pair

std::pair<std::vector<double>, std::vector<double>> AdamBashforthSolver::solve() {
  std::vector<double> ys(this->n, this->y0); // Initialize with size n and initial value y0
  std::vector<double> ts(this->n, 0); // Initialize time vector
  double y = this->y0;
  double t = 0;
  DoubleFunction f = function.toDoubleFunction();
  
  // 4-step Runge-Kutta for initial steps
  for (int i = 0; i < std::min(this->n, 4); ++i) {
    double k1 = this->dt * f(t, y);
    double k2 = this->dt * f(t + 0.5 * this->dt, y + 0.5 * k1);
    double k3 = this->dt * f(t + 0.5 * this->dt, y + 0.5 * k2);
    double k4 = this->dt * f(t + this->dt, y + k3);
    
    y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
    t += this->dt;
    ys[i] = y;
    ts[i] = t;
  }
  
  // Adam-Bashforth method for the rest of the steps
  for (int i = 4; i < this->n; ++i) {
    y = ys[i - 1] + this->dt * (55 * f(t, ys[i - 1]) - 59 * f(t - this->dt, ys[i - 2]) + 37 * f(t - 2 * this->dt, ys[i - 3]) - 9 * f(t - 3 * this->dt, ys[i - 4])) / 24;
    t += this->dt;
    
    ys[i] = y;
    ts[i] = t;
  }
  
  return std::make_pair(ts, ys);
}
