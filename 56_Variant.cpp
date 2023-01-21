#include <utility>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <memory>
#include <type_traits>
#include <functional>
#include <regex>
#include <boost/variant.hpp>
    
template<class F>
struct pseudo_method {
  F f;
  // enable C++17 class type deduction:
  pseudo_method( F&& fin ):f(std::move(fin)) {}

  // Koenig lookup operator->*, as this is a pseudo-method it is appropriate:
  template<class Variant> // maybe add SFINAE test that LHS is actually a variant.
  friend decltype(auto) operator->*( Variant&& var, pseudo_method const& method ) {
    // var->*method returns a lambda that perfect forwards a function call,
    // behaving like a method pointer basically:
    return [&](auto&&...args)->decltype(auto) {
      // use visit to get the type of the variant:
      return boost::apply_visitor(
        [&](auto&& self)->decltype(auto) {
          // decltype(x)(x) is perfect forwarding in a lambda:
          return method.f( decltype(self)(self), decltype(args)(args)... );
        },
        std::forward<Variant>(var)
      );
    };
  }
};

template<class F>
pseudo_method<std::decay_t<F>> make_pseudo_method(F&& f){return {std::forward<F>(f)};}

auto print = make_pseudo_method([](auto&& self, auto&&...args)->decltype(auto) {
  return decltype(self)(self).print( decltype(args)(args)... );
});

struct A {
  void print( std::ostream& os ) const {
    os << "A";
  }
};
struct B {
  void print( std::ostream& os ) const {
    os << "B";
  }
};

int main()
{
    boost::variant<A,B> var = A{};

    (var->*print)(std::cout);
    
    var = B{};
    
    (var->*print)(std::cout);
}