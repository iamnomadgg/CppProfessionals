#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <string>
#include <future>

void my_callback(void *x)
{
    std::cout << "the value is: " << reinterpret_cast<long>(x); // will probably compile
}
void register_callback(void (*fp)(void *), void *arg); // probably a C API

int main()
{
    long x;
    std::cin >> x;
    register_callback(my_callback,
                      reinterpret_cast<void *>(x)); // hopefully this doesn't lose information...
}