// Assessment.hh
#include <vector>
#include <functional>

class Assessment {
public:
    Assessment(const std::function<double(double)>& y_exact, double t_final, double dt);
    void setApproximation(const std::vector<double>& y_approx);
    double computeL2NormAtFinal();
    double computeL2NormFull();

private:
    std::function<double(double)> y_exact;
    double t_final;
    double dt;
    std::vector<double> y_approx;
};
