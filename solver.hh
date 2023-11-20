#include <vector>
#include <iostream>
#include <functional>
#include <stdexcept>

class Solver {
public:
  Solver(double (*function)(double, double), double initialY, double deltaTime, int steps)
    : f(function), y0(initialY), dt(deltaTime), n(steps) {}
  
  double forwardEuler();
  double backwardEuler();
  double rungeKutta4();
  double adamsBashforth4(std::function<double(Solver&)> initialMethod);
  
private:
  double (*f)(double, double);
  double y0;
  double dt;
  int n;
  
  // Utility method for backward Euler
  double solveBackwardEulerEquation(double y, double t, double dt, double (*f)(double, double)){
    return y;
  };
};

