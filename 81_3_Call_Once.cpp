#include <mutex>
#include <iostream>

std::once_flag flag;

void do_something(){
    std::call_once(flag, []()
                   { std::cout << "Happens once" << std::endl; });
    std::cout << "Happens every time" << std::endl;
}

int main(){
    do_something();
    do_something();
    do_something();
    return 0;
}