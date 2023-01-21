#include <iostream>

int& getX() {
int x = 42;
return x;
}

int main() {
int& r = getX();
std::cout << r << "\n";
}