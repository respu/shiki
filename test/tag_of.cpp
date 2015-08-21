//==================================================================================================
/*
  Copyright 2015 Joel FALCOU

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <shiki/tag_of.hpp>
#include <shiki/make_expr.hpp>
#include <shiki/as_terminal.hpp>

#include <nstest.hpp>

// Expression tag
struct foo {};

NSTEST_CASE( "Check tag_of conformity")
{
  NSTEST_EXPR_IS( shiki::tag_of(shiki::make_expr<foo>(1.)), foo                   );
  NSTEST_EXPR_IS( shiki::tag_of(shiki::as_terminal(1.))   , shiki::tag::terminal_ );
}

NSTEST_CASE( "Check tag_of_ conformity")
{
  NSTEST_TYPE_IS( shiki::tag_of_<decltype(shiki::make_expr<foo>(1.))> , foo );
  NSTEST_TYPE_IS( shiki::tag_of_<decltype(shiki::as_terminal(1.))>    , shiki::tag::terminal_);
}
