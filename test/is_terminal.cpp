//==================================================================================================
/*
  Copyright 2015 Joel FALCOU

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <shiki/is_terminal.hpp>
#include <shiki/make_expr.hpp>

#include <nstest.hpp>

// Expression tag
struct foo {};

NSTEST_CASE( "Check that random values are not terminal")
{
  NSTEST_EXPECT( shiki::is_terminal(4.f) == false );
  NSTEST_EXPECT( shiki::is_terminal(foo{}) == false );
}

NSTEST_CASE( "Check that random expression is not terminal")
{
  NSTEST_EXPECT( shiki::is_terminal(shiki::make_expr<foo>(1.)) == false );
}

struct value_ : shiki::tag::terminal_ {};

NSTEST_CASE( "Check that terminal expressions are terminal")
{
  NSTEST_EXPECT( shiki::is_terminal(shiki::make_expr<shiki::tag::terminal_>(1.)) == true );
  NSTEST_EXPECT( shiki::is_terminal(shiki::make_expr<value_>("lol")) == true );
}
