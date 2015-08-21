//==================================================================================================
/*!
  @file

  Defines the is_expr function and meta-function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <type_traits>
#include <boost/config.hpp>

namespace shiki
{
  namespace detail
  {
    template<typename Expr, typename Enable = void>
    struct is_expr_ : std::false_type
    {};

    template<typename T>
    struct is_expr_<T, typename T::is_expr> : std::true_type
    {};
  }

  /*!
    @brief Checks if a type is an expression

    @tparam  xpr  Expression to check
  **/
  template<typename T>
  using is_expr_ = typename detail::is_expr_<T>::type;

  /*!
    @brief Checks if a value is an expression

    @param  xpr  Value to check
  **/
  template<typename Expr> BOOST_FORCEINLINE constexpr auto is_expr(Expr const&)
  {
    return is_expr_<Expr>{};
  }
}
