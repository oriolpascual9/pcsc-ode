#include "Assessment.hh"
#include <iostream>
#include <cmath>

void Assessment::setApproximation(const std::vector<double>& y_approx) {
    this->y_approx = y_approx;
}

double Assessment::computeL2NormAtFinal() {
    if (y_approx.empty()) {
        std::cerr << "Approximation not set.\n";
        return -1.0;
    }

    double y_exact_final = y_exact(t_final);
    double y_approx_final = y_approx.back();
    return std::sqrt(std::pow(y_exact_final - y_approx_final, 2));
}

    // Optional: Compute L2 norm for each term (can be enabled if needed)
double Assessment::computeL2NormFull() {
    if (y_approx.empty()) {
        std::cerr << "Approximation not set.\n";
        return -1.0;
    }

    double sum = 0.0;
    double time = 0.0;
    for (size_t i = 0; i < y_approx.size(); ++i, time += dt) {
        double diff = y_exact(time) - y_approx[i];
        sum += diff * diff;
    }
    return std::sqrt(sum * dt);
}
