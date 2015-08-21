//==================================================================================================
/*
  Copyright 2015 Joel FALCOU

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <shiki/is_terminal.hpp>
#include <shiki/as_expr.hpp>
#include <shiki/as_terminal.hpp>
#include <shiki/value.hpp>

#include <nstest.hpp>

// Expression tag
struct foo {};

NSTEST_CASE( "Check that random values are not terminal")
{
  NSTEST_EXPECT_NOT( shiki::is_terminal(4.f) );
  NSTEST_EXPECT_NOT( shiki::is_terminal(foo{}) );
}

NSTEST_CASE( "Check that random expression is not terminal")
{
  NSTEST_EXPECT_NOT( shiki::is_terminal(shiki::as_expr<foo>(1.)));
}

NSTEST_CASE( "Check that terminal expressions are terminal")
{
  NSTEST_EXPECT( shiki::is_terminal(shiki::as_terminal(1.)) );
  NSTEST_EXPECT( shiki::is_terminal(shiki::as_terminal("lol")) );
}

struct value_ : shiki::tag::terminal_ {};

NSTEST_CASE( "Check that custom terminal expressions are terminal")
{
  NSTEST_EXPECT( shiki::is_terminal(shiki::as_terminal<value_>(1.)) );
  NSTEST_EXPECT( shiki::is_terminal(shiki::as_terminal<value_>("lol")) );
}
