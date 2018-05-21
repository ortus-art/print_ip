#pragma once

/// \defgroup lib Library


/// \addtogroup lib
/// \brief Library that able to print
/// @{

#include <algorithm>
#include <array>
#include <iterator>
#include <iostream>
#include <string>
#include "print_traits.h"
namespace print_ip
{

/// Print std::tuple variable in dot-decimal notation
/// \details It is not inteded to use it directly. Usually is
/// used by function that takes a tuple.
/// Stored values has to support output stream shift operator.
///
/// \tparam _Args list of tuple types
/// \param[in] std::ostream stream output stream to use
/// \param[in] value the value to emit to the stream
template<typename T, std::size_t... _Is>
void print(std::ostream &stream,
                      const T& values,
                      std::index_sequence<_Is...>)
{
    ((stream << (_Is == 0? "" : ".") << std::get<_Is>(values)), ...);
}

/// Print std::tuple variable in dot-decimal notation
/// \details Prints all items in the container separated by a dot.
/// Stored values has to support output stream shift operator.
///
/// \tparam _Args list of tuple types
/// \param[in] std::ostream stream output stream to use
/// \param[in] value the value to emit to the stream
template<typename... _Args>
auto print(std::ostream &stream, const std::tuple<_Args...> &values)
{
   print(stream, values, std::index_sequence_for<_Args...>{});
   stream << std::endl;
}


/// Type definition for decimal octet
using ip_octet_t = uint8_t;


/// Print any integral variable in dot-decimal notation
/// \tparam T type of integral variable
/// \tparam enable_if_integral_v<T> verification if it is an itegral type
/// \param[in] std::ostream stream output stream to use
/// \param[in] value the value to emit to the stream
template<typename T, enable_if_integral_t<T> = 0>
void print(std::ostream &stream, const T& value)
{
  const auto octets = reinterpret_cast<const ip_octet_t* >(&value);
  auto dot {false};
  for(auto i = sizeof (T); i > 0 ;)
  {
      if(dot)
          stream << '.';
      else
          dot = true;
      stream << static_cast<size_t>(octets[--i]);
  }
  stream << std::endl;
}

/// Print supported container variables in dot-decimal notation
/// \details Prints all items in container separated by dot.
/// Stored values has to support output stream shift operator.
///
/// \tparam T type of std::vector or std::list
/// \tparam enable_if_container_t<T> verification if it is a supported type
/// \param[in] std::ostream stream output stream to use
/// \param[in] value the value to emit to the stream

template<typename T, enable_if_container_t<T> = 0>
void print(std::ostream &stream, const T& values)
{
  auto dot {false};
  for(const auto & value: values)
  {
      if(dot)
          stream << '.';
      else
          dot = true;
      stream << value;
  }
  stream << std::endl;
}



/// Print any value that is not from defined suported types to the stream
/// \details Print any string that comes to std::cout
/// \param[in] value value to print
/// \sa \ref std::string
void print(std::ostream &stream, const std::string & value)
{
    stream << value << std::endl;
}

} //namespace print_ip

/// @}
// End of group lib
