#include "Reader/Reader_ODE.hh"
#include <gtest/gtest.h>

class ReaderODETest : public ::testing::Test {
protected:
    // Setup for each test
    void SetUp() override {
        // Initialize any required objects or state
    }

    // Teardown after each test
    void TearDown() override {
        // Clean up any resources or state
    }

    // Test fixture for shared resources
    Reader_ODE readerODE;
};

TEST_F(ReaderODETest, ChooseParseFunction_ValidInput) {
    std::istringstream input("poly\n3*y^2\ny\nexp\n-2^y\nn");
    std::cin.rdbuf(input.rdbuf());

    Function function = readerODE.choose_parse_function();

    DoubleFunction f = function.toDoubleFunction();

    EXPECT_EQ(f(100.0, 3), 19); // 3*3^2 - 2^3
}

TEST_F(ReaderODETest, ChooseParseFunction_InvalidInput) {
    std::istringstream input("invalid\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_THROW({
                     readerODE.choose_parse_function();
                 }, Exception);
}

TEST_F(ReaderODETest, ParseFunctionPoly_ValidInput) {
    Function function;
    std::string input = "3*y^2";

    readerODE.parse_function_poly(function, input);

    // no exception should be thrown
    DoubleFunction f = function.toDoubleFunction();
    EXPECT_EQ(f(100.0, 2.0), 12.0); // 3*2^2
}

TEST_F(ReaderODETest, ParseFunctionPoly_InvalidInput) {
    Function function;
    std::string input = "invalid";

    EXPECT_THROW({
                     readerODE.parse_function_poly(function, input);
                 }, std::invalid_argument);
}

TEST_F(ReaderODETest, ParseFunctionExp_ValidInput) {
    Function function;
    std::string input = "2.5^y";

    readerODE.parse_function_exp(function, input);

    // no exception should be thrown
    DoubleFunction f = function.toDoubleFunction();
    EXPECT_EQ(f(0.0, 2.0), 6.25); // 2.5^2
}

TEST_F(ReaderODETest, ParseFunctionExp_InvalidInput) {
    Function function;
    std::string input = "invalid";

    EXPECT_THROW({
                     readerODE.parse_function_exp(function, input);
                 }, Exception);
}


TEST_F(ReaderODETest, ReadODEProblem_ValidInput) {
    std::istringstream input("1\n1\n0.1\n10\npoly\n3*y^2\nn\n");
    std::cin.rdbuf(input.rdbuf());

    Problem_ODE problem = readerODE.read_ODE_Problem();

    EXPECT_EQ(problem.getInitY(), 1);
    EXPECT_EQ(problem.getInitT(), 1);
    EXPECT_EQ(problem.getDeltaT(), 0.1);
    EXPECT_EQ(problem.getN(), 10);

    DoubleFunction f = problem.getFunction().toDoubleFunction();
    EXPECT_EQ(f(9092.0, 2.0), 12.0); // 3*2^2
}

TEST_F(ReaderODETest, ReadODEProblem_InvalidInput) {
    std::istringstream input("invalid\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_THROW({
                     readerODE.read_ODE_Problem();
                 }, Exception);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

