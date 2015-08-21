//==================================================================================================
/*!
  @file

  Defines the terminal_ tag

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <shiki/expr.hpp>
#include <boost/config.hpp>

namespace shiki
{
  namespace tag
  {
    struct terminal_
    {
      using is_terminal = void;
    };
  }

  /*
    Specialize expr for terminal like tag
  */
  template<typename Terminal, typename Value/*, typename Domain = default_domain*/>
  struct expr<Terminal(Value), typename Terminal::is_terminal> //: ops::arithmetic::support//: Domain::grammar
  {
    using is_expr = void;

    // Expression are not DefaultConstructible nor Assignable
    expr() = delete;
    expr& operator=(expr const& x) = delete;
    expr& operator=(expr && x)     = delete;

    // Build expression from a tree
    BOOST_FORCEINLINE constexpr expr(Value const& x) : value_{ x }                      {}
    BOOST_FORCEINLINE constexpr expr(Value&&      x) : value_{ std::forward<Value>(x) } {}

    // Expression are CopyConstructible and MoveConstructible
    BOOST_FORCEINLINE constexpr expr(expr const& x) = default;
    BOOST_FORCEINLINE constexpr expr(expr && x)     = default;

    // Trees are Visitable
    template<typename Visitor>
    BOOST_FORCEINLINE constexpr decltype(auto) accept(Visitor&& visitor) const
    {
      return std::forward<Visitor>(visitor)(Terminal{},value_);
    }

    BOOST_FORCEINLINE           Value&        value()         { return value_; }
    BOOST_FORCEINLINE constexpr Value const&  value() const   { return value_; }

    protected:
    Value value_;
  };

  template<typename Value> using terminal = expr<shiki::tag::terminal_(Value)>;
}
