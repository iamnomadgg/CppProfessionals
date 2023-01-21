#include <iostream>
struct BaseException
{
        virtual const char *what() const { return "BaseExceptionDeneme"; }
};
struct DerivedException : BaseException
{
        // "virtual" keyword is optional here
        virtual const char *what() const { return "DerivedExceptionDeneme"; }
};
int main(int argc, char **argv)
{
        try
        {
                try
                {
                        throw DerivedException();
                }
                catch (const BaseException &e)
                {
                        std::cout << "First catch block: " << e.what() << std::endl;
                        // Output ==> First catch block: DerivedException
                        throw e; // This changes the exception to BaseException
                        // instead of the original DerivedException!
                }
        }
        catch (const BaseException &e)
        {
                std::cout << "Second catch block: " << e.what() << std::endl;
                // Output ==> Second catch block: BaseException
        }
        return 0;
}