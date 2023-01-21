#include <iostream>

typedef int Fn(int); // Fn is a type-of function that accepts an int and returns an int

// Note that MyFn() is of type 'Fn'
int MyFn(int i) { return 2*i; }

class Class {
public:
    // Note that Static() is of type 'Fn'
    static int Static(int i) { return 3*i; }
}; // Class

int main() {
    Fn *fn; // fn is a pointer to a type-of Fn
    fn = &MyFn; // Point to one function
    std::cout << fn(3) <<std::endl; // Call it
    fn = &Class::Static; // Point to the other function
    std::cout << fn(4) <<std::endl; // Call it
} // main()