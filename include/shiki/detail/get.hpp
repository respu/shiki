//==================================================================================================
/*!
  @file

  Defines the get helper function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <boost/config.hpp>
#include <functional>

namespace shiki { namespace detail
{
  template<typename Expr>
  BOOST_FORCEINLINE constexpr decltype(auto) get(std::reference_wrapper<Expr>&& xpr)
  {
    return std::forward<std::reference_wrapper<Expr>>(xpr).get();
  }

  template<typename Expr>
  BOOST_FORCEINLINE constexpr decltype(auto) get(Expr&& xpr)
  {
    return std::forward<Expr>(xpr);
  }
} }
