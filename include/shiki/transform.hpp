//==================================================================================================
/*!
  @file

  Defines the transform base class

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <shiki/detail/get.hpp>
#include <boost/config.hpp>
#include <type_traits>
#include <functional>
#include <utility>

namespace shiki
{
  /*!
    @ingroup group-api
    @brief CRTP base class for tree transforms

    @tparam Visitor user-defined class performing the tree visit
  **/
  template<typename Visitor> struct transform
  {
    template<typename Expr> BOOST_FORCEINLINE constexpr decltype(auto) visit(Expr&& xpr) const
    {
      return detail::get(std::forward<Expr>(xpr)).accept( static_cast<Visitor const&>(*this) );
    }

    template<typename Expr> BOOST_FORCEINLINE decltype(auto) visit(Expr&& xpr)
    {
      return detail::get(std::forward<Expr>(xpr)).accept( static_cast<Visitor&>(*this) );
    }
  };
}
