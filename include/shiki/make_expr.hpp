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

namespace shiki
{
  /*!
    @brief Build a new expression from a pack of children

    @tparam Tag   Expression tag
    @param  Args  Expression children
  **/
  template<typename Tag, typename... Args> inline auto make_expr(Args const&... children)
  {
    auto tree = [&](auto visitor) { return visitor(Tag{},children...); };
    return expr<decltype(tree)>(tree);
  }
}
