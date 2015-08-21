//==================================================================================================
/*
  Copyright 2015 Joel FALCOU

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <shiki/as_expr.hpp>
#include <nstest.hpp>

// Expression tag
struct foo {};

// Type to embed
struct bar
{
  bar() = default;
  bar(bar const&) { nb_copy++; }
  static int nb_copy;
};

int bar::nb_copy = 0;

NSTEST_CASE( "Check as_expr non-copy policy")
{
  bar f,g,h;

  NSTEST_EXPECT( bar::nb_copy == 0);

  shiki::as_expr<foo> ( shiki::as_expr<foo> ( shiki::as_expr<foo>(g,f)
                                                , shiki::as_expr<foo>(g,h)
                                                )
                        );

  NSTEST_EXPECT( bar::nb_copy == 0);
}
