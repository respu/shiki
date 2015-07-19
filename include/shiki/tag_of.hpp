//==================================================================================================
/*!
  @file

  Defines the tag_of function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

namespace shiki
{
  /*!
    @brief Return the tag of a given expression

    @param  xpr  Expression to retrieve tag from
  **/
  template<typename Expr> inline constexpr auto tag_of(Expr const& xpr)
  {
    return xpr.accept( [](auto tag, auto... args) { ignore(args...); return tag; } );
  }

  /*!
    @brief Return the type of the tag of a given expression

    @taparam Expr Expression to retrieve the tag from
  **/
  template<typename Expr> using tag_of_ = decltype(tag_of(std::declval<Epr>()));
}
