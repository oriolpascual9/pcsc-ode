#include <vector>
#include <iostream>
#include <functional>
#include <stdexcept>
#include "solver.hh"

double Solver::forwardEuler() {
  double y = y0;
  double t = 0;
  
  for (int i = 0; i < n; ++i) {
    y += dt * f(t, y);
    t += dt;
  }
  
  return y;
}

double Solver::adamsBashforth4(std::function<double(Solver&)> initialMethod) {
  std::vector<double> ys(4, y0); // Initialize with size 4 and initial value y0
  double y = y0;
  double t = 0;
  
  // Compute the initial steps using a smaller solver instance
  for (int i = 0; i < std::min(n, 4); ++i) {
    Solver initialSolver(f, y0, dt, i + 1);
    ys[i] = initialMethod(initialSolver);
  }
  
  for (int i = 4; i < n; ++i) {
    y = ys[3] + dt * (55 * f(t, ys[3]) - 59 * f(t - dt, ys[2]) + 37 * f(t - 2 * dt, ys[1]) - 9 * f(t - 3 * dt, ys[0])) / 24;
    t += dt;
    
    // Update previous y values
    for (int j = 3; j > 0; --j) {
      ys[j] = ys[j - 1];
    }
    ys[0] = y;
  }
  
  return y;
}

double Solver::backwardEuler() {
  double y = y0;
  double t = 0;
  
  for (int i = 0; i < n; ++i) {
    // Assuming a direct solution method is available
    y = solveBackwardEulerEquation(y, t, dt, f);
    t += dt;
  }
  
  return y;
}

double Solver::rungeKutta4() {
  double y = y0;
  double t = 0;
  
  for (int i = 0; i < n; ++i) {
    double k1 = dt * f(t, y);
    double k2 = dt * f(t + dt / 2, y + k1 / 2);
    double k3 = dt * f(t + dt / 2, y + k2 / 2);
    double k4 = dt * f(t + dt, y + k3);
    
    y += (k1 + 2*k2 + 2*k3 + k4) / 6;
    t += dt;
  }
  
  return y;
}