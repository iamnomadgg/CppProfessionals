#include <iostream>
#include <random>
int main()
{
    std::random_device crypto_random_generator;
    std::uniform_int_distribution<int> int_distribution(0, 9);
    int actual_distribution[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10000; i++)
    {
        int result = int_distribution(crypto_random_generator);
        actual_distribution[result]++;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << actual_distribution[i] << " ";
    }
    std::random_device rd;
    std::cout << '\n' << rd.entropy() << '\n';
    return 0;
}