//==================================================================================================
/*!
  @file

  Defines the make_expr function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <shiki/support/terminal.hpp>
#include <shiki/expr.hpp>
#include <utility>

namespace shiki
{
  template<typename Arg> inline auto as_terminal(Arg&& arg)
  {
    return expr<tag::terminal_(typename std::decay<Arg>::type)>(std::forward<Arg>(arg));
  }

  template<typename Terminal, typename Arg> inline auto as_terminal(Arg&& arg)
  {
    return expr<Terminal(typename std::decay<Arg>::type)>(std::forward<Arg>(arg));
  }

  template<typename Terminal,typename Arg>
  inline decltype(auto) as_terminal(expr<Terminal(Arg)>&& arg)
  {
    return std::forward<expr<Terminal(Arg)>>(arg);
  }

  template<typename Terminal, typename T,typename Arg>
  inline decltype(auto) as_terminal(expr<T(Arg)>&& arg)
  {
    return expr<Terminal(Arg)>(std::forward<expr<T(Arg)>>(arg).value());
  }
}
