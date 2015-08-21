//==================================================================================================
/*
  Copyright 2015 Joel FALCOU

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <shiki/as_expr.hpp>
#include <shiki/as_terminal.hpp>
#include <shiki/value.hpp>

#include <nstest.hpp>

NSTEST_CASE( "Check that terminal expressions have value()")
{
  auto t = shiki::as_terminal(13.37);
  NSTEST_EQUAL(shiki::value(t), 13.37);

  shiki::value(t) = 73.31;
  NSTEST_EQUAL(shiki::value(t), 73.31);

  NSTEST_TYPE_IS( shiki::value_<decltype(t)>, double );
}

struct value_ : shiki::tag::terminal_ {};

NSTEST_CASE( "Check that custom terminal expressions have value()")
{
  auto t = shiki::as_terminal<value_>(13.37);
  NSTEST_EQUAL(shiki::value(t), 13.37);

  shiki::value(t) = 73.31;
  NSTEST_EQUAL(shiki::value(t), 73.31);

  NSTEST_TYPE_IS( shiki::value_<decltype(t)>, double );
}
