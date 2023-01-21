#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <string>
#include <future>

int main()
{
    void bad_strlen(char *);
    const char *s = "hello, world!";
    bad_strlen(s);// compile error
    bad_strlen(const_cast<char *>(s)); // OK, but it's better to make bad_strlen accept const char*

    const int x = 123;
    int &mutable_x = const_cast<int &>(x);
    mutable_x = 456; // may compile, but produces *undefined behavior*
}