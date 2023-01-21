#include <memory>
#include <iostream>
using namespace std;

int main()
{
    shared_ptr sp2;
    {
        shared_ptr sp1(new int(5)); // give ownership to sp1
        cout << *sp1 << endl;       // prints 5
        sp2 = sp1;                  // copy sp2 from sp1; both have ownership of resource
        cout << *sp1 << endl;       // prints 5
        cout << *sp2 << endl;       // prints 5
    }                               // sp1 goes out of scope and is destroyed; sp2 has sole ownership of resource
    cout << *sp2 << endl;
} // sp2 goes out of scope; nothing has ownership, so resource is freed