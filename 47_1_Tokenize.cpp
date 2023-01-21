#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
	auto str = "The quick brown fox"s;
	vector<string> tokens;
 
	for (auto i = strtok(&str[0], " "); i != nullptr; i = strtok(nullptr, " ")) tokens.push_back(i);
 
	copy(cbegin(tokens), cend(tokens), ostream_iterator<string>(cout, "\n"));
}