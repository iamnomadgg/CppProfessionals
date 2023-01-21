#include <iostream>
#include <iomanip>
using namespace std;

void print_asterisks(int count) {
if (count < 0) {
throw std::invalid_argument("count cannot be negative!");
}
while (count--) { putchar('*'); }
}

auto main() -> int
{
    print_asterisks(0);
    cout << "sdfssdfsdf";
}