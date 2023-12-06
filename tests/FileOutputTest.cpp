#include "Output/FileOutput.h"
#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>

class FileOutputTest : public ::testing::Test {
protected:
    std::string testOutputPath = "test_output_directory";
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

// Test createDataFile method for successful file creation
TEST_F(FileOutputTest, OutputSuccessTest) {
    FileOutput fileOutput(ys, ts, testOutputPath);
    ASSERT_NO_THROW(fileOutput.output());

    // Read the file and check its contents
    std::ifstream dataFile(testOutputPath + "/data.dat");
    ASSERT_TRUE(dataFile.is_open());

    std::string line;
    size_t i = 0;
    while (getline(dataFile, line)) {
        std::stringstream ss(line);
        double t, y;
        ss >> t >> y;
        ASSERT_EQ(t, ts[i]);
        ASSERT_EQ(y, ys[i]);
        ++i;
    }
    ASSERT_EQ(i, ys.size());
}

// Test createDataFile method for handling errors
TEST_F(FileOutputTest, OutputErrorTest) {
    // Using an invalid path to induce an error
    FileOutput fileOutput(ys, ts, "invalid_path");
    ASSERT_THROW(fileOutput.output(), Exception);
}