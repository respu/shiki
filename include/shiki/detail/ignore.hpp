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

namespace shiki { namespace detail
{
  /*!
    @ingroup shiki-detail
    @brief Variadic unsued parameter silencer
  **/
  template<typename... Args> inline void ignore(Args&&...) {}
} }
