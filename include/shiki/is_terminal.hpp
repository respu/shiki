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

#include <shiki/detail/ignore.hpp>
#include <shiki/support/terminal.hpp>
#include <shiki/tag_of.hpp>
#include <shiki/expr.hpp>
#include <type_traits>

namespace shiki
{
  /*!
    @brief Checks if an expression or a tag is a terminal

    @param  xpr  Expression to check
  **/
  template<typename Xpr> constexpr auto is_terminal(Xpr const& xpr)
  {
    detail::ignore(xpr);
    return std::is_base_of<tag::terminal_,Xpr>{};
  }

  template<typename T> constexpr auto is_terminal(expr<T> const& xpr)
  {
    return is_terminal(tag_of(xpr));
  }

  /*!
    @brief Checks if an expression is a terminal

    @tparam  xpr  Expression to check
  **/
  template<typename Expr> using is_terminal_ = decltype( is_terminal( std::declval<Expr>() ) );
}
