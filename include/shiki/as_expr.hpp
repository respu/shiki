//==================================================================================================
/*!
  @file

  Defines the as_expr function

  @copyright 2015 Joel Falcou

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#pragma once

#include <shiki/expr.hpp>
#include <boost/config.hpp>
#include <type_traits>
#include <functional>
#include <utility>

namespace shiki
{
  namespace detail
  {
    template<typename T>
    using is_rvalue = typename std::enable_if< std::is_rvalue_reference<T&&>::value >::type*;

    template<typename T>
    using is_not_rvalue = typename std::enable_if< !std::is_rvalue_reference<T&&>::value >::type*;

    template<typename T> BOOST_FORCEINLINE auto as_ref( T&& arg, is_not_rvalue<T> = 0 )
    {
      return std::reference_wrapper<typename std::remove_reference<T>::type>(arg);
    }

    template<typename T> BOOST_FORCEINLINE decltype(auto) as_ref( T&& arg, is_rvalue<T> = 0 )
    {
      return std::forward<T>(arg);
    }

    /*
      This function builds an expression containing a auto-generated lambda that :
        - capture all the children by value
        - call a given visitor on the tag + the unpacked children

      Capture is done by value as the upper level takes care of wrapping pre-existing expression
      in reference_wrapper.
    */
    template<typename Tag, typename... Child>
    BOOST_FORCEINLINE auto as_expr(Child const&... children)
    {
      auto tree = [=]( auto&& v ) { return std::forward<decltype(v)>(v)( Tag{}, children... ); };
      return expr<decltype(tree)>(tree);
    }
  }

  /*!
    @brief Build a new expression from a pack of children

    @tparam Tag   Expression tag
    @param  Child  Expression children
  **/
  template<typename Tag, typename... Child> BOOST_FORCEINLINE auto as_expr(Child&&... children)
  {
    return detail::as_expr<Tag>( detail::as_ref(std::forward<Child>(children))... );
  }
}
