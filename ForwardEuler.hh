#ifndef FORWARD_EULER_SOLVER_HH
#define FORWARD_EULER_SOLVER_HH

#include "DiscreteSolver.hpp"

template<typename T>
class ForwardEulerSolver : public DiscreteSolver<T> {
public:
    using DiscreteSolver<T>::DiscreteSolver; // Inherit constructor

    T solve() override {
        T y = this->y0;
        double t = 0;

        for (int i = 0; i < this->n; ++i) {
            y += this->dt * this->f(t, y);
            t += this->dt;
        }

        return y;
    }
};

#endif // FORWARD_EULER_SOLVER_HH
