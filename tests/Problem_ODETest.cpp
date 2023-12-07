#include <gtest/gtest.h>
#include "Problem/Problem_ODE.hh"
#include "Solver/RungeKuttaSolver.h"
#include "Function/Function.h"
#include "FunctionComponent/FunctionComponent.h"

class ProblemODETest : public ::testing::Test {
protected:
    Function func = Function();
    FunctionComponent fc1;
    double init_y = 1.0;
    double init_t = 0.0;
    double delta_t = 1e-5;;
    int n = 10;
    Problem_ODE problem_ode;

    ProblemODETest() : problem_ode(init_y, init_t, delta_t, n, func) {}

    virtual void SetUp() {
        fc1.generateTermComponent(3,3); // 3*y^3
        func.addComponent(fc1);
        problem_ode =  Problem_ODE(init_y, init_t, delta_t, n, func);
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right before the destructor).
    }
};

TEST_F(ProblemODETest, ConstructorTest) {
    // Test constructor functionality
    EXPECT_EQ(init_y, problem_ode.getInitY());
    EXPECT_EQ(init_t, problem_ode.getInitT());
    EXPECT_EQ(delta_t, problem_ode.getDeltaT());
    EXPECT_EQ(n, problem_ode.getN());
}

TEST_F(ProblemODETest, SolveTest) {
    RungeKuttaSolver solver = *new RungeKuttaSolver();
    problem_ode.solve(solver);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
