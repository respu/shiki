//==================================================================================================
/*!
  @file

  Defines the is_terminal function and meta-function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <shiki/support/terminal.hpp>
#include <shiki/tag_of.hpp>
#include <shiki/expr.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace shiki
{
  namespace detail
  {
    template<typename Expr, typename Enable = void>
    struct is_terminal_ : std::false_type
    {};

    template<typename T>
    struct is_terminal_<T, typename T::is_terminal> : std::true_type
    {};
  }

  /*!
    @brief Checks if an expression or a tag is a terminal

    @param  xpr  Expression to check
  **/
  template<typename Xpr> BOOST_FORCEINLINE constexpr auto is_terminal(Xpr const&)
  {
    return typename detail::is_terminal_<Xpr>::type{};
  }

  template<typename T,typename S> BOOST_FORCEINLINE constexpr auto is_terminal(expr<T,S> const& xpr)
  {
    return is_terminal(tag_of(xpr));
  }

  /*!
    @brief Checks if an expression is a terminal

    @tparam  xpr  Expression to check
  **/
  template<typename Expr> using is_terminal_ = decltype( is_terminal( std::declval<Expr>() ) );
}
