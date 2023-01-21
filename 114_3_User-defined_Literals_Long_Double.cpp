#include <iostream>
long double operator"" _km(long double val)
{
    return val * 1000.0;
}
long double operator"" _mi(long double val)
{
    return val * 1609.344;
}
int main()
{
    std::cout << "3 km = " << 3.0_km << " m\n";
    std::cout << "3 mi = " << 3.0_mi << " m\n";
    return 0;
}