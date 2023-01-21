#include <iostream>
using namespace std;

class C1{ };
class C2{ public: ~C2() = delete; };
class C3 : public C2{ };

int main() {
cout << boolalpha << is_destructible<int>() << endl; // prints true
cout << boolalpha << is_destructible<C1>() << endl; // prints true
cout << boolalpha << is_destructible<C2>() << endl; // prints false
cout << boolalpha << is_destructible<C3>() << endl; // prints false
}