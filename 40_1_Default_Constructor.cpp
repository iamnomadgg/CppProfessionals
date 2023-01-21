#include <iostream>
using namespace std;

class C{
public:
    int i;
    // does have automatically generated default constructor (same as implicit one)
    C() = default;
    //C() = delete;
    C( int i ) : i(i){}
};

int main() {
    C c1; // default constructed
    C c2( 1 ); // constructed with the int taking constructor
    cout << c1.i << " - " << c2.i;
}
