//==================================================================================================
/*
  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <nstest/unit.hpp>
#include <brigand/list.hpp>

namespace shiki
{
  namespace ops
  {
    struct adl {};
  }

  template<typename Representation>
  struct expr : ops::adl {};

  namespace ops
  {
    struct plus_ {};

    template<typename L, typename R>
    auto operator+(L const& l, R const& r)
    {
      auto tree = [&](auto visitor) { return visitor( plus_{},l,r); };
      return expr<decltype(tree)>{};
    }
  }

}

struct foo : shiki::ops::adl {};

NSTEST_CASE( "blob")
{
  auto x = foo{} + foo{};
  std::cout << typeid(x).name() << "\n";
  auto y = x + foo{};
  std::cout << typeid(y).name() << "\n";
}
