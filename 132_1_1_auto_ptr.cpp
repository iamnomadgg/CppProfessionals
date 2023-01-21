#include <memory>
#include <iostream>
using namespace std;

//(auto_ptr deprecated in C++11)
//(auto_ptr removed in C++17)
int main()
{
    auto_ptr ap1(new int(5));
    cout << *ap1 << endl;           // prints 5
    auto_ptr ap2(ap1);              // copy ap2 from ap1; ownership now transfers to ap2
    cout << *ap2 << endl;           // prints 5
    cout << ap1 == nullptr << endl; // prints 1; ap1 has lost ownership of resource
}