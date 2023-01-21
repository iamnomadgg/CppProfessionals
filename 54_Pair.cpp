#include <string>
#include <iostream>

int main(){
    std::pair<int, int> p1 = std::make_pair(1, 2);
    std::pair<int, int> p2 = std::make_pair(2, 2);
    if (p1 == p2)
        std::cout << "equals" << p1.first << p1.second<< p2.first << p2.second;
    else
        std::cout << "not equal" << p1.first << p1.second<< p2.first << p2.second;
        //statement will show this, because they are not identical
    return 0;
}