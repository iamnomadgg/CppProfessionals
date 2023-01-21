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


std::vector<int> GenerateRandVec(int numOfNums,
		int min, int max);
std::vector<int> GenerateFibList(int maxNums);

int main()
{
	std::vector<int> vecVals = GenerateRandVec(10, 1, 50);
	std::vector<int> evenVecVals;
	for (auto val : vecVals)
		std::cout << val << "\n";

	std::cout << "\n----------\n";

	/*std::sort(vecVals.begin(), vecVals.end(),
			[](int x, int y){ return x < y; });*/
	/*std::copy_if(vecVals.begin(), vecVals.end(),
			std::back_inserter(evenVecVals),
			[](int x){return (x % 2) == 0;});*/
	/*int sum = 0;
	std::for_each(vecVals.begin(), vecVals.end(),
	[&](int x) { sum += x; });
	std::cout << "Sum: " << sum << "\n";*/
	/*int divisor;
	std::vector<int> vecVals2;
	std::cout << "List of the values Divisable by: ";
	std::cin >> divisor;
	std::copy_if(vecVals.begin(), vecVals.end(),
			std::back_inserter(vecVals2),
			[divisor](int x){return (x % divisor) == 0;});*/
	/*std::vector<int> doubleVec;
	std::for_each(vecVals.begin(), vecVals.end(),
			[&](int x){doubleVec.push_back(x * 2);});*/
	/*std::vector<int> vec1 = {1, 2, 3, 4, 5};
	std::vector<int> vec2 = {1, 2, 3, 4, 5};
	std::vector<int> vec3(5);
	std::transform(vec1.begin(), vec1.end(),
			vec2.begin(), vec3.begin(),
			[](int x, int y){ return x + y; });*/
	/*int age = 16;
	bool canIVote = (age >= 18) ? true : false;
	std::cout.setf(std::ios::boolalpha);
	std::cout << "Can I Vote: " << canIVote << "\n";*/
	/*std::function<int(int)> Fib = 
	[&Fib](int n){return n < 2 ? n :
	Fib(n - 1) + Fib(n - 2);};
	std::cout << "Fib 20 : " << Fib(20) << std::endl;*/
	std::vector<int> listOfFibs = GenerateFibList(10);

	for (auto val : listOfFibs)
		std::cout << val << "\n";
	
	return 0;
}

std::vector<int> GenerateFibList(int maxNums){
	std::vector<int> listOfFibs;
	int i = 0;

	std::function<int(int)> Fib = 
		[&Fib](int n){return n < 2 ? n :
		Fib(n - 1) + Fib(n - 2);};

	while(i < maxNums){
		listOfFibs.push_back(Fib(i++));
	}
	return listOfFibs;
}

std::vector<int> GenerateRandVec(int numOfNums,
		int min, int max)
{
	std::vector<int> vecValues;
	srand(time(NULL));
	int i = 0, randVal = 0;
	while (i < numOfNums){
		randVal = min + std::rand() % ((max + 1) - min);
		vecValues.push_back(randVal);
		i++;
	}
	return vecValues;
}