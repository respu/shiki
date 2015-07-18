#include <iostream>
#include <tuple>

namespace ops
{
  namespace arithmetic
  {
    struct support {};
  }
}

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
    return v(terminal_<T>{},*this);
  }
  
  protected:
  T expr_;
};

template<typename Expr> struct is_terminal_ : std::false_type {};
template<typename V>    struct is_terminal_<terminal_<V>> : std::true_type {};

template<typename Expr> constexpr bool is_terminal(Expr const&)
{
  return is_terminal_<Expr>::value;
}

struct eval
{
  template<typename Tag, typename... Args>
  inline constexpr auto operator()(Tag const& op, Args const&... args) const
  {
    return op(args.accept(*this)...);
  }

  template<typename V, typename Value>
  inline constexpr auto operator()(terminal_<V> const&, Value&& v) const
  {
    return std::forward<Value>(v).value();
  }
};

template<typename Expr> constexpr auto arity(Expr const& xpr)
{
  return xpr.accept ( [](auto tag, auto... args) { return std::integral_constant<std::size_t,is_terminal(tag) ? 0u : sizeof...(args)>{}; } ); 
}

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
    inline auto operator*(expr<L> const& l, expr<R> const & r  )
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

int main()
{
  foo a{4}, b{7}, x;

  x = (a + b)*(b + a);
  std::cout << x.value() << "\n";
  std::cout << arity(a) << "\n";
  std::cout << arity(a + b) << "\n";
}
