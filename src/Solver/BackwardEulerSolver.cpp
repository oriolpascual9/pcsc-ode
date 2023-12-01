#include "Solver/BackwardEulerSolver.h"
#include <utility> // for std::pair
#include <vector>

std::pair<std::vector<double>, std::vector<double>> BackwardEulerSolver::solve() {
  std::vector<double> ys(this->n);
  std::vector<double> ts(this->n);
  double y = this->y0;
  double t = 0;
  DoubleFunction f = function.toDoubleFunction();
  
  for (int i = 0; i < this->n; ++i) {
    y = solveBackwardEulerEquation(y, t, this->dt, f);
    t += this->dt;
    
    ys[i] = y; // Store the updated y-value
    ts[i] = t; // Store the updated time
  }
  
  return std::make_pair(ts, ys);
}

double BackwardEulerSolver::solveBackwardEulerEquation(double y, double t, double dt, DoubleFunction f) const {
  const double tolerance = 1e-6;
  const int maxIterations = 100;
  double y_next = y; // Initial guess for y_next
  
  for (int i = 0; i < maxIterations; ++i) {
    // Newton's method formula
    double g = y_next - y - dt * f(t + dt, y_next);
    double g_prime = 1 - (f(t + dt, y_next) - f(t, y))/2;
    
    // Avoid division by zero
    if (fabs(g_prime) < 1e-12) {
      break;
    }
    
    double y_next_new = y_next - g / g_prime;
    
    // Check for convergence
    if (fabs(y_next_new - y_next) < tolerance) {
      return y_next_new;
    }
    
    y_next = y_next_new;
  }
  
  // Return the best approximation after maxIterations
  return y_next;
}
