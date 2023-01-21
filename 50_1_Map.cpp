#include <cstring>
#include <iostream>
#include <map>
using namespace std;
 
int main() {
	std::map < std::string, int > ranking { std::make_pair("stackoverflow", 2),
	std::make_pair("docs-beta", 1) };
	std::cout << ranking[ "stackoverflow" ] << std::endl;
	std::cout << ranking.at("stackoverflow") << std::endl;
}