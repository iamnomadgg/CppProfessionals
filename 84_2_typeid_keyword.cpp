#include <cassert>
#include <typeinfo>
#include <iostream>

struct Base {
virtual ~Base() = default;
};
struct Derived : Base {};

int main()
{
    Base* b = new Derived;
    assert(typeid(*b) == typeid(Derived{})); // OK
    std::cout << typeid(*b).name() << std::endl;
    return 0;
}