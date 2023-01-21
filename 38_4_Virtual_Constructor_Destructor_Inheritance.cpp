#include <iostream>
using namespace std;

class base {
public:
    base() { f("base constructor"); }
    ~base() { f("base destructor"); }
    virtual const char* v() { return "base::v()"; }
    void f(const char* caller) {
    cout << "When called from " << caller << ", " << v() << " gets called.\n";
    }
};

class derived : public base {
public:
    derived() { f("derived constructor"); }
    ~derived() { f("derived destructor"); }
    const char* v() override { return "derived::v()"; }
};

int main() {
    //derived d;
    base b;
}