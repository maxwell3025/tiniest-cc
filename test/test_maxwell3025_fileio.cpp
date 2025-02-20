#include <string>

#include "gtest/gtest.h"
extern "C" {
    #include "../src/common/load_file.h"
}

TEST(read_file, correctness) {
    char *hello_world = read_file("hello_world.txt");

    std::string expected = std::string("Hello World!\n");
    std::string actual = std::string(hello_world);

    EXPECT_TRUE(actual.length() > 0);
    EXPECT_EQ(actual.length(), expected.length());
    EXPECT_EQ(actual, expected);

    free(hello_world);
}

