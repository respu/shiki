//==================================================================================================
/*
  Copyright 2015 Joel FALCOU

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <shiki/arity.hpp>
#include <shiki/as_expr.hpp>
#include <shiki/as_terminal.hpp>

#include <nstest.hpp>

// Expression tag
struct value_ : shiki::tag::terminal_ {};
struct foo {};

NSTEST_CASE( "Check that terminal expressions have arity of 0")
{
  NSTEST_EQUAL( shiki::arity(shiki::as_terminal(1.f)), 0u );
  NSTEST_EQUAL( shiki::arity(shiki::as_terminal<value_>(69u)), 0u );

  NSTEST_TYPE_IS( shiki::arity_<decltype(shiki::as_terminal(1.f))>
                , (std::integral_constant<std::size_t,0u>)
                );
  NSTEST_TYPE_IS( shiki::arity_<decltype(shiki::as_terminal<value_>(69u))>
                , (std::integral_constant<std::size_t,0u>)
                );
}

NSTEST_CASE( "Check that random expressions have proper arity")
{
  NSTEST_EQUAL( shiki::arity(shiki::as_expr<foo>(42))     , 1u );
  NSTEST_EQUAL( shiki::arity(shiki::as_expr<foo>(6,9))    , 2u );
  NSTEST_EQUAL( shiki::arity(shiki::as_expr<foo>(1,'O',1)), 3u );
  NSTEST_EQUAL( shiki::arity(shiki::as_expr<foo>(1,3,3,7)), 4u );
  NSTEST_EQUAL( shiki::arity(shiki::as_expr<foo>('h','e','l','l','o',' ','c','+','+','!')), 10u );

  NSTEST_TYPE_IS( (shiki::arity_<decltype(shiki::as_expr<foo>(42))>)
                , (std::integral_constant<std::size_t,1u>)
                );
  NSTEST_TYPE_IS( (shiki::arity_<decltype(shiki::as_expr<foo>(6,9))>)
                , (std::integral_constant<std::size_t,2u>)
                );
  NSTEST_TYPE_IS( (shiki::arity_<decltype(shiki::as_expr<foo>(1,'O',1))>)
                , (std::integral_constant<std::size_t,3u>)
                );
  NSTEST_TYPE_IS( (shiki::arity_<decltype(shiki::as_expr<foo>(1,3,3,7))>)
                , (std::integral_constant<std::size_t,4u>)
                );
  NSTEST_TYPE_IS( (shiki::arity_<decltype(shiki::as_expr<foo>('h','e','l','l','o',' ','c','+','+','!'))>)
                , (std::integral_constant<std::size_t,10u>)
                );
}
