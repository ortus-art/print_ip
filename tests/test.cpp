#include <gtest/gtest.h>

#include "print_ip.h"

/// \defgroup tests Tests


/// \addtogroup tests
/// \brief Unit tests covering \ref lib
/// @{

using namespace testing;


/// Verify that all type traits are calculated correctly
/// \details It verifies that std::vector and std::list
/// are detected correctly.
TEST(traits_verification, verify_container_type_checking)
{
    ASSERT_TRUE(print_ip::is_container_v<std::vector<int>>);
    ASSERT_TRUE(print_ip::is_container_v<std::vector<char>>);
    ASSERT_TRUE(print_ip::is_container_v<std::vector<double>>);
    ASSERT_TRUE(print_ip::is_container_v<std::list<int>>);
    ASSERT_TRUE(print_ip::is_container_v<std::list<char>>);
    ASSERT_TRUE(print_ip::is_container_v<std::list<double>>);
    ASSERT_TRUE(print_ip::is_container_v<const std::vector<int>>);
    ASSERT_TRUE(print_ip::is_container_v<volatile std::vector<char>>);
    ASSERT_TRUE(print_ip::is_container_v<const std::vector<double>>);
    ASSERT_TRUE(print_ip::is_container_v<volatile std::list<int>>);
    ASSERT_TRUE(print_ip::is_container_v<const std::list<char>>);
    ASSERT_TRUE(print_ip::is_container_v<volatile std::list<double>>);

    ASSERT_FALSE(print_ip::is_container_v<char>);
    ASSERT_FALSE(print_ip::is_container_v<int>);
    ASSERT_FALSE(print_ip::is_container_v<std::tuple<char>>);

}

/// Verify that all type traits are calculated correctly
/// \details It verifies that integral types are detected
/// correctly.
TEST(traits_verification, verify_integral_type_checking)
{
    ASSERT_TRUE(print_ip::is_integral_v<int>);
    ASSERT_TRUE(print_ip::is_integral_v<char>);
    ASSERT_TRUE(print_ip::is_integral_v<short>);
    ASSERT_TRUE(print_ip::is_integral_v<const int>);
    ASSERT_TRUE(print_ip::is_integral_v<volatile char>);
    ASSERT_TRUE(print_ip::is_integral_v<const short>);

    ASSERT_FALSE(print_ip::is_integral_v<double>);
    ASSERT_FALSE(print_ip::is_integral_v<std::list<char>>);
    ASSERT_FALSE(print_ip::is_integral_v<float>);
    ASSERT_FALSE(print_ip::is_integral_v<const std::vector<int>>);
    ASSERT_FALSE(print_ip::is_container_v<std::string>);
}

/// Verify that all integral types are correctly presented
/// \details It verifies that char, short, int and long
/// types are correctly presented in dot-decimal notation
TEST(library_verification, verify_integral_type_values)
{

    char char_value{-1};
    short short_value{0};
    auto int_value{2130706433};
    auto long_value{8875824491850138409L};
    std::ostringstream os;

    print_ip::print(os, char_value);
    print_ip::print(os, short_value);
    print_ip::print(os, int_value);
    print_ip::print(os, long_value);
    ASSERT_EQ(os.str(),
              "255\n"
              "0.0\n"
              "127.0.0.1\n"
              "123.45.67.89.101.112.131.41\n"
              );
}

/// Verify that strings are correctly presented
/// \details Generally there is no handling of
/// std::string. It is presented as is.
/// So these tests verify that the correct
/// overload is called
TEST(library_verification, verify_string_values)
{

    auto str_value = std::string("127");
    auto str_value1 = std::string("127.0.0.1");
    std::ostringstream os;

    print_ip::print(os, str_value);
    print_ip::print(os, str_value1);
    ASSERT_EQ(os.str(),
              "127\n"
              "127.0.0.1\n"
              );
}

/// Verify that std::list is correctly presented
/// \details It verifies that  the correct overloads are
/// called and presented in right order.
TEST(library_verification, verify_list_values)
{

    std::list<int> int_list{192,168, 0,2};
    std::list<short> short_list{127,0, 0,1};
    std::list<long> long_list{127,0, 0,1};
    std::list<std::string> string_list{"127","0", "0","1"};
    std::ostringstream os;

    print_ip::print(os, int_list);
    print_ip::print(os, short_list);
    print_ip::print(os, long_list);
    print_ip::print(os, string_list);

    ASSERT_EQ(os.str(),
              "192.168.0.2\n"
              "127.0.0.1\n"
              "127.0.0.1\n"
              "127.0.0.1\n");
}

/// Verify that std::vector correctly presented
/// \details It verifies that  the correct overloads are
/// called and presented in right order.
TEST(library_verification, verify_vector_values)
{

    std::vector<int> int_list{192,168, 0,2};
    std::vector<short> short_list{127,0, 0,1};
    std::vector<long> long_list{127,0, 0,1};
    std::vector<std::string> string_list{"127","0", "0","1"};
    std::ostringstream os;

    print_ip::print(os, int_list);
    print_ip::print(os, short_list);
    print_ip::print(os, long_list);
    print_ip::print(os, string_list);

    ASSERT_EQ(os.str(),
              "192.168.0.2\n"
              "127.0.0.1\n"
              "127.0.0.1\n"
              "127.0.0.1\n");
}

/// Verify that std::tuple correctly presented
/// \details It verifies that  the correct overloads are
/// called and presented in right order.
TEST(library_verification, verify_tuple_values)
{

    auto tuple_value = std::make_tuple(192,168, 0,3);
    auto tuple_long = std::make_tuple(192L,168L, 0,4L);
    auto tuple_unsigned = std::make_tuple(192U,168U, 0,5U);
    auto tuple_unsigned_long = std::make_tuple(192UL,168UL, 0,6UL);

    std::ostringstream os;

    print_ip::print(os, tuple_value);
    print_ip::print(os, tuple_long);
    print_ip::print(os, tuple_unsigned);
    print_ip::print(os, tuple_unsigned_long);

    ASSERT_EQ(os.str(),
              "192.168.0.3\n"
              "192.168.0.4\n"
              "192.168.0.5\n"
              "192.168.0.6\n");
}


/// Main stub function that calls all tests
int main(int argc, char **argv) {
  InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



/// @}
// End of group tests
