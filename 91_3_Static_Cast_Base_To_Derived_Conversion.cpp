#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <string>
#include <future>

int main()
{
    struct Base
    {
    };
    struct Derived : Base
    {
    };
    Derived d;
    Base *p1 = &d;
    Derived *p2 = p1;                         // error; cast required
    Derived *p3 = static_cast<Derived *>(p1); // OK; p2 now points to Derived object
    Base b;
    Base *p4 = &b;
    Derived *p5 = static_cast<Derived *>(p4); // undefined behaviour since p4 does not
                                              // point to a Derived object
    Derived d;
    Base &r1 = d;
    Derived &r2 = r1;                         // error; cast required
    Derived &r3 = static_cast<Derived &>(r1); // OK; r3 now refers to Derived object
}