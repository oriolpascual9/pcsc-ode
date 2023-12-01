#include "Solver/ForwardEulerSolver.h"
#include <utility> // for std::pair
#include <vector>

std::pair<std::vector<double>, std::vector<double>> ForwardEulerSolver::solve() const {
  std::vector<double> ys(this->n); // Vector to store y-values
  std::vector<double> ts(this->n); // Vector to store time values
  double y = this->y0;
  double t = 0;
  
  for (int i = 0; i < this->n; ++i) {
    ys[i] = y; // Store the current y-value
    ts[i] = t; // Store the current time
    
    y += this->dt * this->f(t, y); // Update y for the next iteration
    t += this->dt; // Update time for the next iteration
  }
  
  return std::make_pair(ts, ys); // Return the pair of vectors
}