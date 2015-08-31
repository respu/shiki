//==================================================================================================
/*!
  @file

  Defines the as_node function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <shiki/as_terminal.hpp>
#include <shiki/is_expr.hpp>
#include <boost/config.hpp>
#include <type_traits>
#include <functional>
#include <utility>

namespace shiki
{
  namespace detail
  {
    template<typename T>
    using if_not_expr = typename std::enable_if<!is_expr_<typename std::decay<T>::type>::value>::type*;

    template<typename T>
    using if_expr = typename std::enable_if<is_expr_<typename std::decay<T>::type>::value>::type*;
  }

  /*!
    @ingroup group-api
    @brief Smart expression converter

    For any given argument @c arg, returns either the perfect forwarded argument if it's already
    an expression or a terminal expression containing a copy of said argument.

    @param arg Object to potentially turns into an expression

    @return An expression optimally containing @c arg
  **/
  template<typename Arg>
  BOOST_FORCEINLINE constexpr decltype(auto) as_node(Arg&& arg, detail::if_not_expr<Arg> = 0)
  {
    return shiki::as_terminal(std::forward<Arg>(arg));
  }

  /// @overload
  template<typename Arg>
  BOOST_FORCEINLINE constexpr decltype(auto) as_node(Arg&& arg, detail::if_expr<Arg> = 0)
  {
    return std::forward<Arg>(arg);
  }
}
