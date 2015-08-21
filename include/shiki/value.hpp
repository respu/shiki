//==================================================================================================
/*!
  @file

  Defines the value function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <boost/config.hpp>
#include <type_traits>

namespace shiki
{
  /*!
    @ingroup group-api
    @brief Terminal value accessor

    Retrieves a potentially mutable reference to the contents of a terminal node.

    @param xpr Expression to extract the value from
  **/
  template<typename Expr> BOOST_FORCEINLINE constexpr
  auto value(Expr& xpr) -> decltype(xpr.value())
  {
    return xpr.value();
  }

  /// @overload
  template<typename Expr> BOOST_FORCEINLINE constexpr
  auto value(Expr const& xpr) -> decltype(xpr.value())
  {
    return xpr.value();
  }

  /*!
    @ingroup group-meta
    @brief Return the type contained by a given terminal expression

    For any given terminal Expression, returns the cv-qualified type of its value.

    @tparam Expr Expression to retrieve the value type from
  **/
  template<typename Expr>
  using value_ = typename std::decay<decltype(value(std::declval<Expr>()))>::type;
}
