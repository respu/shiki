//==================================================================================================
/*!
  @file

  Defines the as_terminal function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <shiki/terminal.hpp>
#include <shiki/expr.hpp>
#include <boost/config.hpp>
#include <utility>

namespace shiki
{
  /*!
    @ingroup group-api
    @brief Terminal node creation


  **/
  template<typename Type, typename... Args>
  BOOST_FORCEINLINE constexpr auto as_terminal(Args&&... args)
  {
    return expr<tag::terminal_(Type)>(Type{std::forward<Args>(args)...});
  }

  /// @overload
  template<typename Arg> BOOST_FORCEINLINE constexpr auto as_terminal(Arg&& arg)
  {
    return expr<tag::terminal_(typename std::decay<Arg>::type)>(std::forward<Arg>(arg));
  }

  /*!
    @ingroup group-api
    @brief In-place terminal node creation


  **/
  template<typename Terminal, typename Type, typename... Args>
  BOOST_FORCEINLINE constexpr auto as_terminal(Args&&... args)
  {
    return expr<Terminal(Type)>(Type{std::forward<Args>(args)...});
  }

  /// @overload
  template<typename Terminal, typename Arg>
  BOOST_FORCEINLINE constexpr auto as_terminal(Arg&& arg)
  {
    return expr<Terminal(typename std::decay<Arg>::type)>(std::forward<Arg>(arg));
  }

  /// @overload
  template<typename Terminal,typename Arg>
  BOOST_FORCEINLINE decltype(auto) as_terminal(expr<Terminal(Arg)>&& arg)
  {
    return std::forward<expr<Terminal(Arg)>>(arg);
  }
}
