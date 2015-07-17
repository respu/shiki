#include <iostream>

template<typename Xpr> struct expr
{
   Xpr expr_;

   template<typename Visitor>
   inline constexpr auto accept(Visitor v) const
   {
     return expr_(v);
   }
};

template<typename T> struct terminal_ {};

template<typename T> struct expr<terminal_<T>>
{
   T expr_;

   T const& value() const { return expr_; };
   T&       value()       { return expr_; };

   template<typename Visitor>
   inline constexpr auto accept(Visitor v) const
   {
      return v(terminal_<T>{},expr_);
   }
};

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
  return expr<decltype(tree)>{tree};
}

template<typename L, typename R>
inline auto operator*( expr<L> const& l, expr<R> const & r )
{
  auto tree = [=](auto visitor) { return visitor(times_{},l,r); };
  return expr<decltype(tree)>{tree};
}

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

struct foo : expr<terminal_<int>>
{
  using parent = expr<terminal_<int>>;

  foo(int v = 0) { parent::value() = v; }

  template<typename X> foo& operator=(expr<X> const& x)
  {
    parent::value() = x.accept(eval{});
    return *this;
  }
};

int main()
{
   foo a{4}, b{7}, x;

   x = (a + b)*(b + a);
   std::cout << x.expr_ << "\n";
}
