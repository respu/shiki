//==================================================================================================
/*!
  @file

  Defines the ignore helper function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <boost/config.hpp>
#include <utility>

namespace shiki
{
  template< typename Tree/*, typename Domain = default_domain*/
          , typename IsTerminal = void
          > struct expr //: Domain::grammar
  {
    // Expression type-tag
    using is_expr = void;

    // Expression are not DefaultConstructible nor Assignable
    expr() = delete;
    expr& operator=(expr const& x) = delete;
    expr& operator=(expr && x)     = delete;

    // Build expression from a tree
    BOOST_FORCEINLINE constexpr expr(Tree const& x) : tree_{ x }                     {}
    BOOST_FORCEINLINE constexpr expr(Tree&&      x) : tree_{ std::forward<Tree>(x) } {}

    // Expression are CopyConstructible and MoveConstructible
    BOOST_FORCEINLINE constexpr expr(expr const& x) = default;
    BOOST_FORCEINLINE constexpr expr(expr && x)     = default;

    // Trees are Visitable
    template<typename Visitor>
    BOOST_FORCEINLINE constexpr decltype(auto) accept(Visitor&& visitor) const
    {
      return tree_(std::forward<Visitor>(visitor));
    }

    protected:
    Tree tree_;
  };
}
