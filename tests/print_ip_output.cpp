#include <gtest/gtest.h>

#include <cstdlib>
#include <fstream>
#include <print_ip.h>

TEST(PrintIP, print_check) {
    const char* check_string = 
        "255\n"
        "0.0\n"
        "127.0.0.1\n"
        "123.45.67.89.101.112.131.41\n"
        "Hello, World!\n"
        "100.200.300.400\n"
        "400.300.200.100\n";

    const char* command = "./print_ip > print_check_test.txt";
    const int return_system_value = std::system(command);
    std::ifstream check_file;

    check_file.open("print_check_test.txt");
    if (!check_file.is_open()) 
        FAIL();

    std::string check_print;
    std::ostringstream sstream;
    sstream << check_file.rdbuf();
    check_print = sstream.str();

    EXPECT_EQ(return_system_value, 0);
    EXPECT_EQ(check_print, check_string);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}