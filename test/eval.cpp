#include <iostream>

namespace ops
{
  namespace arithmetic
  {
    struct support {};
  }
}

template<typename... Rules> struct grammar : Rules... {};

template<typename Xpr> struct expr : ops::arithmetic::support
{
  expr(Xpr const& x) : expr_{ x }               {}
  expr(Xpr&&      x) : expr_{ std::forward(x) } {}

  template<typename Visitor>
  inline constexpr auto accept(Visitor v) const
  {
    return expr_(v);
  }

  protected:
  Xpr expr_;
};

template<typename T> struct terminal_ {};

template<typename T> struct expr<terminal_<T>> : ops::arithmetic::support
{
  T const& value() const { return expr_; };
  T&       value()       { return expr_; };

  expr() {}
  expr(terminal_<T> const& x) : expr_{ x }               {}
  expr(terminal_<T>&&      x) : expr_{ std::forward(x) } {}

  template<typename Visitor>
  inline constexpr auto accept(Visitor v) const
  {
    return v(terminal_<T>{},expr_);
  }

  protected:
  T expr_;
};

struct eval
{
  template<typename Tag, typename... Args>
  inline constexpr auto operator()(Tag const& op, Args const&... args) const
  {
    return op(args.accept(*this)...);
  }

  template<typename V>
  inline constexpr auto operator()(terminal_<V> const&, V const& v) const
  {
    return v;
  }
};

namespace ops
{
  namespace arithmetic
  {
    struct plus_
    {
       template<typename L, typename R>
       inline constexpr auto operator()(L const& l, R const& r) const
       {
          return l+r;
       }
    };

    struct times_
    {
       template<typename L, typename R>
       inline constexpr auto operator()(L const& l, R const& r) const
       {
          return l*r;
       }
    };

    template<typename L, typename R>
    inline auto operator+( expr<L> const& l, expr<R> const & r )
    {
      auto tree = [=](auto visitor) { return visitor(plus_{},l,r); };
      return expr<decltype(tree)>(tree);
    }

    template<typename L, typename R>
    inline auto operator*( expr<L> const& l, expr<R> const & r )
    {
      auto tree = [=](auto visitor) { return visitor(times_{},l,r); };
      return expr<decltype(tree)>(tree);
    }
  }
}

template<typename Value> using terminal =  expr<terminal_<Value>>;

struct foo : terminal<int>
{
  using parent = terminal<int>;

  foo(int v = 0) { parent::value() = v; }

  template<typename X> foo& operator=(expr<X> const& x)
  {
    parent::value() = x.accept(eval{});
    return *this;
  }
};

/***************************************************************************************************
Generated assembly :
  subq  $8, %rsp
  movl  $121, %esi
  movl  std::cout, %edi
  call  operator<<(int)
  movl  "\n", %esi
  movq  %rax, %rdi
  call  std::operator<<(char const*)
  xorl  %eax, %eax
  addq  $8, %rsp
***************************************************************************************************/
int main()
{
  foo a{4}, b{7}, x;

  x = (a + b)*(b + a);
  std::cout << x.value() << "\n";
}
