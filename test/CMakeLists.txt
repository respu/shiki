##===================================================================================================
##                 Copyright 2015   Joel Falcou
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

include(make_unit)
include(make_coverage)

add_definitions(-DBOOST_ENABLE_ASSERT_HANDLER)

set ( SOURCES
      is_terminal.cpp
      make_expr.cpp
      tag_of.cpp
      #arity.cpp
    )

make_unit( "shiki" ${SOURCES})
make_coverage("shiki" ${SOURCES})
