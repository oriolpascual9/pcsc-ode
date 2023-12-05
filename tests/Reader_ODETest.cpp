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
    std::istringstream input("poly\n3*x^2\nn\n");
    std::cin.rdbuf(input.rdbuf());

    Function function = readerODE.choose_parse_function();

    // Verify that function contains the expected components
    // This depends on the implementation of your Function class
}

TEST_F(ReaderODETest, ChooseParseFunction_InvalidInput) {
    std::istringstream input("invalid\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_THROW({
                     readerODE.choose_parse_function();
                 }, std::exception);
}

TEST_F(ReaderODETest, ParseFunctionPoly_ValidInput) {
    Function function;
    std::string input = "3*x^2";

    readerODE.parse_function_poly(function, input);

    // Verify that function contains the expected polynomial components
}

TEST_F(ReaderODETest, ParseFunctionPoly_InvalidInput) {
    Function function;
    std::string input = "invalid";

    EXPECT_THROW({
                     readerODE.parse_function_poly(function, input);
                 }, std::exception);
}

TEST_F(ReaderODETest, ParseFunctionExp_ValidInput) {
    Function function;
    std::string input = "2.5^y";

    readerODE.parse_function_exp(function, input);

    // Verify that function contains the expected exponential components
}

TEST_F(ReaderODETest, ParseFunctionExp_InvalidInput) {
    Function function;
    std::string input = "invalid";

    EXPECT_THROW({
                     readerODE.parse_function_exp(function, input);
                 }, std::exception);
}

TEST_F(ReaderODETest, ReadODEProblem_ValidInput) {
    std::istringstream input("1\n1\n0.1\n10\npoly\n3*x^2\nn\n");
    std::cin.rdbuf(input.rdbuf());

    Problem_ODE problem = readerODE.read_ODE_Problem();

    // Verify the properties of the returned Problem_ODE object
    // This depends on the implementation of your Problem_ODE class
    // For example:
    EXPECT_EQ(problem.getInitY(), 1);
    EXPECT_EQ(problem.getInitT(), 1);
    EXPECT_EQ(problem.getDeltaT(), 0.1);
    EXPECT_EQ(problem.getN(), 10);
    // ... and other checks as needed
}

TEST_F(ReaderODETest, ReadODEProblem_InvalidInput) {
    std::istringstream input("invalid\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_THROW({
                     readerODE.read_ODE_Problem();
                 }, std::exception);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

