#ifndef SOLVER_HH
#define SOLVER_HH

template<typename T>
class Solver {
public:
    Solver() {}
    virtual ~Solver() {}

    virtual T solve() = 0;
};

#endif // SOLVER_HH
