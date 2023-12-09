#include "gtest/gtest.h"
#include "FunctionComponent/FunctionComponent.h"

class FunctionComponentTest : public testing::Test {
protected:
    void SetUp() override {
        // Code that runs before each test
    }

    void TearDown() override {
        // Code that runs after each test
    }
};

TEST_F(FunctionComponentTest, GenerateScalarComponent) {
    FunctionComponent fc;
    fc.generateScalarComponent(42.0);

    DoubleFunction f = fc.getFunction();
    EXPECT_EQ(f(2.0, 1.0), 42.0);
}

TEST_F(FunctionComponentTest, GenerateTermComponent) {
    FunctionComponent fc;
    fc.generateTermComponent(3.0, 3.0);

    DoubleFunction f = fc.getFunction();
    EXPECT_EQ(f(2.0, 2.0), 24.0); // 2^3 * 3 = 24
}

TEST_F(FunctionComponentTest, GenerateExpComponent) {
    FunctionComponent fc;
    fc.generateExpComponent(2.0);

    DoubleFunction f = fc.getFunction();
    EXPECT_EQ(f(2.0, 3.0), 8.0); // 2^3 = 8
}

TEST_F(FunctionComponentTest, SumFunctionComponents) {
    FunctionComponent fc1, fc2;
    fc1.generateScalarComponent(5.0);
    fc2.generateTermComponent(2.0, 3.0);

    FunctionComponent result = fc1.sum(fc2);

    DoubleFunction f = result.getFunction();
    EXPECT_EQ(f(7.0, 2.0), 21.0); // 5 + (2^3 * 2) = 13
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}