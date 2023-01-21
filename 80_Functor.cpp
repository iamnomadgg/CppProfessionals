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
#include <cassert>

//A functor is pretty much just a class which defines the operator().
//That lets you create objects which "look like" a function:
// this is a functor
struct add_x
{
	add_x(int val) : x(val) {std::cout << "Created" << std::endl;} // Constructor
	int operator()(int y) const { std::cout << "Operator" << std::endl; return x + y; }

private:
	int x;
};

int main()
{
	// Now you can use it like this:
	add_x add42(42);  // create an instance of the functor class
	int i = add42(8); // and "call" it
	assert(i == 50);  // and it added 42 to its argument

	std::vector<int> in; // assume this contains a bunch of values)
	std::vector<int> out(in.size());
	// Pass a functor to std::transform, which calls the functor on every element
	// in the input sequence, and stores the result to the output sequence
	std::transform(in.begin(), in.end(), out.begin(), add_x(1));
	assert(out[i] == in[i] + 1); // for all i

	return 0;
}