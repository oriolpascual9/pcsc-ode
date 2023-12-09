#include <gtest/gtest.h>
#include "Solver/AdamBashforthSolver.h"
#include "Solver/BackwardEulerSolver.h"
#include "Solver/ForwardEulerSolver.h"
#include "Solver/RungeKuttaSolver.h"
#include "Function/Function.h"
#include <cmath>
#include <vector>
#include <utility>

// Define a common test function and analytical solution
double analyticalSolution(double t, double initialY) { return 1/(initialY-t); };

// Base class for solver tests
class SolverTestBase : public ::testing::Test {
protected:
    const double initialTime = 0.0;
    const double initialY = 1; // y(0) = 1
    const double dt = 1e-8;
    const int n = 1000000; // Number of steps
    Function function;
    FunctionComponent fc1;

    std::vector<double> times;
    std::vector<double> analyticalResults;

    void SetUp() override {
        for (int i = 0; i < n; ++i) {
            double t = i * dt;
            times.push_back(t);
            analyticalResults.push_back(analyticalSolution(t, initialY));
        }
        fc1.generateTermComponent(1.0, 2.0);
        function.addComponent(fc1);
    }

    void checkAccuracy(const std::vector<double>& ys) {
        for (size_t i = 0; i < ys.size(); ++i) {
            EXPECT_NEAR(ys[i], analyticalResults[i], 1e-3) << "Mismatch at step " << i;
        }
    }
};

// Test fixture for AdamBashforthSolver
class AdamBashforthSolverTest : public SolverTestBase {
protected:
    AdamBashforthSolver solver;
    // Initialize solver with specific configuration here if needed
};

// Test fixture for BackwardEulerSolver
class BackwardEulerSolverTest : public SolverTestBase {
protected:
    BackwardEulerSolver solver;
    // Initialize solver with specific configuration here if needed
};

// Test fixture for ForwardEulerSolver
class ForwardEulerSolverTest : public SolverTestBase {
protected:
    ForwardEulerSolver solver;
    // Initialize solver with specific configuration here if needed
};

// Test fixture for RungeKuttaSolver
class RungeKuttaSolverTest : public SolverTestBase {
protected:
    RungeKuttaSolver solver;
    // Initialize solver with specific configuration here if needed
};

TEST_F(AdamBashforthSolverTest, SolverAccuracy) {
    solver.setFunction(function);
    solver.setInitialY(initialY);
    solver.setDeltaT(dt);
    solver.setN(n);
    auto [ts, ys] = solver.solve();
    checkAccuracy(ys);
}

TEST_F(BackwardEulerSolverTest, SolverAccuracy) {
    solver.setFunction(function);
    solver.setInitialY(initialY);
    solver.setDeltaT(dt);
    solver.setN(n);
    auto [ts, ys] = solver.solve();
    checkAccuracy(ys);
}

TEST_F(ForwardEulerSolverTest, SolverAccuracy) {
    solver.setFunction(function);
    solver.setInitialY(initialY);
    solver.setDeltaT(dt);
    solver.setN(n);
    auto [ts, ys] = solver.solve();
    checkAccuracy(ys);
}

TEST_F(RungeKuttaSolverTest, SolverAccuracy) {
    solver.setFunction(function);
    solver.setInitialY(initialY);
    solver.setDeltaT(dt);
    solver.setN(n);
    auto [ts, ys] = solver.solve();
    checkAccuracy(ys);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
