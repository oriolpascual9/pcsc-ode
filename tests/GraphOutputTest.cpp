#include "Output/GraphOutput.h"
#include "gtest/gtest.h"
#include <string>
#include <filesystem>

class GraphOutputTest : public ::testing::Test {
protected:
    std::string testOutputPath = "test_output";
    std::string testId = "test_id";
    std::vector<double> ys = {1.0, 2.0, 3.0};
    std::vector<double> ts = {0.1, 0.2, 0.3};

    // Setup method to create a test directory
    void SetUp() override {
        std::filesystem::create_directory(testOutputPath);
    }

    // TearDown method to clean up
    void TearDown() override {
        std::filesystem::remove_all(testOutputPath);
    }
};

// Test plot method for successful plot creation
TEST_F(GraphOutputTest, OutputSuccessTest) {
    GraphOutput graphOutput(ys, ts, testOutputPath, testId);
    ASSERT_NO_THROW(graphOutput.output());

    // Check if the plot file is created
    ASSERT_TRUE(std::filesystem::exists(testOutputPath + "/test_id.png"));
}

// Test plot method for error handling
TEST_F(GraphOutputTest, OutputErrorTest) {
    // You need a scenario that causes plot() to fail, such as an invalid path
    GraphOutput graphOutput(ys, ts, "invalid_path", testId);
    ASSERT_THROW(graphOutput.output(), Exception);
}
