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

#include <utility>
#include <iostream>

namespace shiki
{
  template<typename Tree/*, typename Domain = default_domain*/> struct expr //: Domain::grammar
  {
    // Expression are not DefaultConstructible nor Assignable
    expr() = delete;
    expr& operator=(expr const& x) = delete;
    expr& operator=(expr && x)     = delete;

    // Build expression from a tree
    inline expr(Tree const& x) : tree_{ x }                     {}
    inline expr(Tree&&      x) : tree_{ std::forward<Tree>(x) } {}

    // Expression are CopyConstructible and MoveConstructible
    inline expr(expr const& x) = default;
    inline expr(expr && x)     = default;

    // Trees are Visitable
    template<typename Visitor> inline decltype(auto) accept(Visitor&& visitor) const
    {
      return tree_(std::forward<Visitor>(visitor));
    }

    protected:
    Tree tree_;
  };
}
