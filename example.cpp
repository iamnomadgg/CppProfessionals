#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <regex>
#include <functional>
#include <vector>
using namespace std;

class Base
{
    int j;
};
class Derived : public Base
{
public:
    int i;
};

int main()
{
    bool b;
    std::cout << sizeof(bool) << " " << sizeof(Derived);
    return 0;
}