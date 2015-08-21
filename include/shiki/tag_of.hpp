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

#include <boost/core/ignore_unused.hpp>
#include <utility>

namespace shiki
{
  /*!
    @ingroup group-api
    @brief Return the tag of a given expression

    For any given Expression, returns an instance of the expression tag type.

    @param  xpr  Expression to process
  **/
  template<typename Expr>
  BOOST_FORCEINLINE constexpr auto tag_of(Expr const& xpr)
  {
    return xpr.accept( [](auto tag, auto... args) { boost::ignore_unused(args...); return tag; } );
  }

  /*!
    @ingroup group-meta
    @brief Return the type of the tag of a given expression

    For any given Expression, returns the type of the expression tag.

    @tparam Expr Expression to retrieve the tag from
  **/
  template<typename Expr> using tag_of_ = decltype(tag_of(std::declval<Expr>()));
}
