Main Page {#mainpage}
=========

@tableofcontents

@section main-preface Preface

----------------------------------------------------------------------------------------------------
Shiki (式) is an [Expression Templates] library toolkit. Largely inspired from [Boost.Proto],
[Boost.Hana] and some years of experiments on writing expression templates, Shiki aims at providing a
lightweight, simple to use and modern implementation of expression templates usable in C++14 and
onward.

@section tutorial-installation Prerequisites and installation

------------------------------------------------------------------------------
To use Shiki in your own project, just add the `include` directory to your
compiler's header search path and you are done. The library relies on a
C++14 compiler and standard library, but nothing else is required. Here is
a table of the current C++14 compilers/toolchains with comments regarding
support for Hana:

Compiler/Toolchain | Status
------------------ | ------
Clang >= 3.5.0     | -
Xcode >= 6.3       | -
GCC   >= 5.1.0     | -
MSVC  >= 15.0      | -

More specifically, Shiki requires a compiler/standard library supporting the
following C++14 features (non-exhaustively):
- Generic lambdas
- Generalized `constexpr`
- Automatically deduced return type
- All the C++14 type traits from the `<type_traits>` header


@section main-howto How to use this documentation

----------------------------------------------------------------------------------------------------
The structure of the reference (available in the menu to the left) goes as
follow:

  - @ref group-concept\n
    Concepts defined and used throughout Shiki.

  - @ref group-api\n
    Documentation for the predefined adaptation of external types to be usable with the library.

  - @ref group-meta\n
    Those functions, classes and macros are components related to the meta-programming required
    to make Shiki works.

  - @ref group-extension\n
    Documentation for extension points for library's components. This documentation is useful
    for people wanting to extended Shiki to work with their own types.

  - @ref group-detail\n
    Documentation for implementation details of the library. This documentation is useful
    for people wanting to work on the library internals and provide patches.


----------------------------------------------------------------------------------------------------

<!-- Links -->
[Expression Templates]: https://en.wikipedia.org/wiki/Expression_templates
[Boost.Proto]: http://www.boost.org/doc/libs/1_58_0/doc/html/proto.html
[Boost.Hana]: http://ldionne.com/hana/
