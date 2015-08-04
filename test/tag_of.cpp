//==================================================================================================
/*
  Copyright 2015 Joel FALCOU

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <shiki/tag_of.hpp>
#include <shiki/make_expr.hpp>

#include <nstest.hpp>

// Expression tag
struct foo {};

NSTEST_CASE( "Check tag_of conformity")
{
  auto x = shiki::make_expr<foo>(1.);

  NSTEST_EXPR_IS( shiki::tag_of(x), foo );
}

NSTEST_CASE( "Check tag_of_ conformity")
{
  auto x = shiki::make_expr<foo>(1.);

  NSTEST_TYPE_IS( shiki::tag_of_<decltype(x)>, foo );
}
