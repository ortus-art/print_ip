#include <iostream>

#include <tuple>

#include "print_ip.h"

/// \defgroup app Application


/// \addtogroup app
/// \brief The application that demonstrates the basic usage
/// of the \ref lib
/// @{

#include "print_ip.h"

/// \defgroup app Application


/// \addtogroup app
/// \brief The application that demonstrates the basic usage
/// of the \ref lib
/// @{

using namespace std;

/// The main point of entry into \ref app
/// \details It demonstrates the basic usage of the \ref lib
int main()
{

      char char_value{-1};
      short short_value{0};
      auto int_value{2130706433};
      auto long_value{8875824491850138409L};
      std::string string_value{"127.0.0.1"};
      std::vector<int> vector_value{192,168, 0,1};
      std::list<int> list_value{192,168, 0,2};
      auto tuple_value = std::make_tuple(192,168, 0,3);

      print_ip::print(std::cout, char_value);
      print_ip::print(std::cout, short_value);
      print_ip::print(std::cout, int_value);
      print_ip::print(std::cout, long_value);
      print_ip::print(std::cout, string_value);
      print_ip::print(std::cout, vector_value);
      print_ip::print(std::cout, list_value);
      print_ip::print(std::cout, tuple_value);

    return 0;
}

/// @}
// End of group app
