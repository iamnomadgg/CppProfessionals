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

std::vector<int> createSemiRandomData()
{
    std::vector<int> data;
    data.push_back(42);
    data.push_back(13);
    for (int i = 52; i; --i)
        data.push_back(i * 2);
    return data;
}
/// Optimized for sorting small vectors
void sortVector(std::vector<int> &v)
{
    if (v.size() == 1)
        return;
    //if (v.size() > 2)
        //return;
    std::sort(v.begin(), v.end());
}
void printVector(const std::vector<int> &v)
{
    for (auto i : v)
        std::cout << i << ' ';
}
int main()
{
    auto vectorToSort = createSemiRandomData();
    sortVector(std::ref(vectorToSort));
    printVector(vectorToSort);
    return 0;
}