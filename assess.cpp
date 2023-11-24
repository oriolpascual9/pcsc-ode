#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

class Assessment {
public:
    Assessment(const std::function<double(double)>& y_exact, double t_final, double dt)
    : y_exact(y_exact), t_final(t_final), dt(dt) {}

    void setApproximation(const std::vector<double>& y_approx) {
        this->y_approx = y_approx;
    }

    double computeL2NormAtFinal() {
        if (y_approx.empty()) {
            std::cerr << "Approximation not set.\n";
            return -1.0;
        }

        double y_exact_final = y_exact(t_final);
        double y_approx_final = y_approx.back();
        return std::sqrt(std::pow(y_exact_final - y_approx_final, 2));
    }

    // Optional: Compute L2 norm for each term (can be enabled if needed)
    double computeL2NormFull() {
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

private:
    std::function<double(double)> y_exact;
    double t_final;
    double dt;
    std::vector<double> y_approx;
};

