#pragma once
/// \addtogroup lib
/// \brief Library that able to print
/// @{
#include <type_traits>

#include <vector>
#include <list>
#include <tuple>

namespace print_ip {

template <typename T>
constexpr auto is_integral_v = std::is_integral<std::remove_cv_t<T>>::value;

/// Verifies if the passed type is of integral type
/// \tparam T - the type to be verified
/// \sa std::enable_if
/// \sa std::is_integral
///
template<typename T>
using enable_if_integral_t =
    typename std::enable_if_t<is_integral_v<T>, int>;


template<typename T>
struct is_container : std::false_type{};

/// Printing to std::vector is supported by the library
/// \tparam _Args - std::list template arguments
template <typename ... _Args>
struct is_container<
        std::vector<_Args...>
       > : std::true_type{};

/// Printing to std::list is supported by the library
/// \tparam _Args - std::list template arguments
template <typename ... _Args>
struct is_container<
        std::list<_Args...>
        > : std::true_type{};

template<typename T>
constexpr auto is_container_v = is_container<std::remove_cv_t<T>>::value;

/// Template type used to tag supported containers
/// \tparam T - type to tag
template<typename T>
using enable_if_container_t =
    typename std::enable_if_t<
        is_container_v<T>
    , int>;


}//namespace print_ip

/// @}
// End of group lib

