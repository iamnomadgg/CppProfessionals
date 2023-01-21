#include <iostream>

unsigned int a;
auto bad_counter = [a] {
return a++; // error: operator() is const
// cannot modify members
};
auto good_counter = [a]() mutable {
return a++; // OK
};

int main()
{
    good_counter(); // 0
    good_counter(); // 1
    good_counter(); // 2
}
