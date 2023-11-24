#ifndef RUNGE_KUTTA_4_SOLVER_HH
#define RUNGE_KUTTA_4_SOLVER_HH

template<typename T>
class RungeKutta4Solver : public DiscreteSolver<T> {
public:
    using DiscreteSolver<T>::DiscreteSolver; // Inherit constructor

    T solve() override {
        T y = this->y0;
        double t = 0;

        for (int i = 0; i < this->n; ++i) {
            T k1 = this->dt * this->f(t, y);
            T k2 = this->dt * this->f(t + this->dt / 2, y + k1 / 2);
            T k3 = this->dt * this->f(t + this->dt / 2, y + k2 / 2);
            T k4 = this->dt * this->f(t + this->dt, y + k3);

            y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
            t += this->dt;
        }

        return y;
    }
};

#endif // RUNGE_KUTTA_4_SOLVER_HH
