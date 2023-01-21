#include <iostream>
#include <tuple>

std::tuple<int, int, int, int> foo(int a, int b) { // or auto (C++14)
    return std::make_tuple(a + b, a - b, a * b, a / b);
}


int main()
{
    auto mrvs = foo(5, 12);
    auto add = std::get<0>(mrvs);
    auto sub = std::get<1>(mrvs);
    auto mul = std::get<2>(mrvs);
    auto div = std::get<3>(mrvs);
    std::cout << add << sub << mul << div << std::endl; // prints "5040"
    return 0;
}