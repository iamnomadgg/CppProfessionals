#include <complex>
#include <iostream>
int main()
{
    using namespace std::literals::complex_literals;
    std::complex<double> c = 2.0 + 1i;                         // {2.0, 1.}
    std::complex<float> cf = 2.0f + 1if;                       // {2.0f, 1.f}
    std::complex<long double> cl = 2.0L + 1il;                 // {2.0L, 1.L}
    std::cout << "abs" << c << " = " << abs(c) << std::endl;   // abs(2,1) = 2.23607
    std::cout << "abs" << cf << " = " << abs(cf) << std::endl; // abs(2,1) = 2.23607
    std::cout << "abs" << cl << " = " << abs(cl) << std::endl; // abs(2,1) = 2.23607
}