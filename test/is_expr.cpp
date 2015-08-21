//==================================================================================================
/*
  Copyright 2015 Joel FALCOU

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <shiki/is_expr.hpp>
#include <shiki/support/terminal.hpp>
#include <shiki/make_expr.hpp>
#include <shiki/as_terminal.hpp>

#include <nstest.hpp>

// Expression tag
struct foo {};
struct value_ : shiki::tag::terminal_ {};

NSTEST_CASE( "Check that random values are not expression")
{
  NSTEST_EXPECT( shiki::is_expr(4.f)   == false );
  NSTEST_EXPECT( shiki::is_expr(foo{}) == false );

  NSTEST_TYPE_IS( shiki::is_expr_<float>, std::false_type );
  NSTEST_TYPE_IS( shiki::is_expr_<foo>, std::false_type );
}

NSTEST_CASE( "Check that random expressions are expressions")
{
  NSTEST_EXPECT( shiki::is_expr(shiki::make_expr<foo>(1.)) == true );
  NSTEST_EXPECT( shiki::is_expr(shiki::make_expr<foo>(1,0,'L')) == true );
  NSTEST_EXPECT( shiki::is_expr(shiki::as_terminal(1.)) == true );
  NSTEST_EXPECT( shiki::is_expr(shiki::as_terminal<value_>("lol")) == true );

  NSTEST_TYPE_IS( shiki::is_expr_<decltype(shiki::make_expr<foo>(1.))>, std::true_type );
  NSTEST_TYPE_IS( shiki::is_expr_<decltype(shiki::make_expr<foo>(1,0,'L'))>, std::true_type );
  NSTEST_TYPE_IS( shiki::is_expr_<decltype(shiki::as_terminal(1.))>, std::true_type );
  NSTEST_TYPE_IS( shiki::is_expr_<decltype(shiki::as_terminal<value_>("lol"))>, std::true_type );
}
