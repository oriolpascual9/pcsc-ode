#include <gtest/gtest.h>
#include "Function/Function.h"
#include "FunctionComponent/FunctionComponent.h"

class FunctionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code that will be executed before each test
    }

    void TearDown() override {
        // Code that will be executed after each test
    }

    // You can add helper methods or member variables that you need for testing
};

TEST_F(FunctionTest, AddOperatorTest) {
Function function;
function.addOperator('+');

// Assuming you have a method to get operators from Function
std::vector<char> operators = function.getOperators();

ASSERT_EQ(1, operators.size());
EXPECT_EQ('+', operators[0]);
}

TEST_F(FunctionTest, AddComponentTest) {
Function function;
FunctionComponent component;

function.addComponent(component);

// Assuming you have a method to get components from Function
std::vector<FunctionComponent> components = function.getComponents();

ASSERT_EQ(1, components.size());
// You may want to check other properties of the added component
}

TEST_F(FunctionTest, ToDoubleFunctionTest) {
Function function;
function.addOperator('+');
function.addOperator('+');
function.addOperator('+');

FunctionComponent fc1;
FunctionComponent fc2;
FunctionComponent fc3;
FunctionComponent fc4;

fc1.generateScalarComponent(5.0); // 5
fc2.generateTermComponent(2.0, 3.0); // 2 * x ^ 3
fc3.generateScalarComponent(-10.0); // -10
fc4.generateExpComponent(4.0); // 4 ^ x

function.addComponent(fc1);
function.addComponent(fc2);
function.addComponent(fc3);
function.addComponent(fc4);

DoubleFunction f = function.toDoubleFunction();

EXPECT_EQ(f(100.0, 2.0), 27.0); // 5 + 2*2^3 - 10 + 4^2

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
