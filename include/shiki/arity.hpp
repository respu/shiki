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

#include <shiki/is_terminal.hpp>
#include <boost/core/ignore_unused.hpp>

namespace shiki
{
  template<typename T> struct terminal;

  /*!
    @ingroup group-api
    @brief Return the number of children of a given expression

    Retrieves the number of children of a given expression.
    Note that terminals have an arity equals to 0.

    @param  xpr  Expression to process
  **/
  template<typename Expr> inline constexpr auto arity(Expr const& xpr)
  {
    return xpr.accept ( [](auto const& tag, auto&&... args)
                      {
                        boost::ignore_unused(tag, args...);
                        return std::integral_constant < std::size_t
                                                      , is_terminal_<decltype(tag)>::value
                                                        ? 0u : sizeof...(args)
                                                      >{};
                      }
                    );
  }

  /*!
    @ingroup group-meta
    @brief Return the type of the arity of a given expression

    For any given Expression, returns the arity of the expression.

    @tparam Expr Expression to retrieve the arity from
  **/
  template<typename Expr> using arity_ = decltype(arity(std::declval<Expr>()));

}
