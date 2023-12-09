#include "Solver/RungeKuttaSolver.h"


std::pair<std::vector<double>, std::vector<double>> RungeKuttaSolver::solve() {
  std::vector<double> ys(this->n); // Vector to store y-values
  std::vector<double> ts(this->n); // Vector to store time values
  double y = this->y0;
  double t = 0;
    DoubleFunction f = function.toDoubleFunction();
    for (int i = 0; i < this->n; ++i) {
    double k1 = this->dt * f(t, y);
    double k2 = this->dt * f(t + this->dt / 2, y + k1 / 2);
    double k3 = this->dt * f(t + this->dt / 2, y + k2 / 2);
    double k4 = this->dt * f(t + this->dt, y + k3);
    
    y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    t += this->dt;
    
    ys[i] = y; // Store the updated y-value
    ts[i] = t; // Store the updated time
  }
  
  return std::make_pair(ts, ys); // Return the pair of vectors
}
