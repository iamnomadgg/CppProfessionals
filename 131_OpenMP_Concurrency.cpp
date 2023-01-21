#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::cout << "begin ";
// This pragma statement hints the compiler that the
// contents within the { } are to be executed in as
// parallel sections using openMP, the compiler will
// generate this chunk of code for parallel execution
#pragma omp parallel sections
    {
// This pragma statement hints the compiler that
// this is a section that can be executed in parallel
// with other section, a single section will be executed
// by a single thread.
// Note that it is "section" as opposed to "sections" above
#pragma omp section
        {
            std::cout << "hello " << std::endl;
            /** Do something **/
        }
#pragma omp section
        {
            std::cout << "world " << std::endl;
            /** Do something **/
        }
#pragma omp section
        {
            std::cout << "forever " << std::endl;
            /** Do something **/
        }
    }
    // This line will not be executed until all the
    // sections defined above terminates
    std::cout << "end" << std::endl;
    return 0;
}