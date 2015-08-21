//==================================================================================================
/*!
  @file

  Master shiki header

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <shiki/arity.hpp>
#include <shiki/as_expr.hpp>
#include <shiki/as_terminal.hpp>
#include <shiki/expr.hpp>
#include <shiki/is_expr.hpp>
#include <shiki/is_terminal.hpp>
#include <shiki/tag_of.hpp>
#include <shiki/value.hpp>

namespace shiki
{
  /*!
    @defgroup group-concept Concepts
    Concepts defined by the library
  **/

  namespace detail
  {
    /*!
      @defgroup group-detail Implementation details
      Implementation details related components
    **/
  }

  /*!
    @defgroup group-extension Extension points
    Extension points for library components
  **/

  /*!
    @defgroup group-meta Compile-time User API
    Meta-programming public API
  **/

  /*!
    @defgroup group-api Runtime User API
    Runtime public API
  **/
}
