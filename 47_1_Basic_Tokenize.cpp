#include <cstring>
#include <iostream>
using namespace std;
 
int main() {
	char str[] = "Hi! I am coding, on C++";
	char* ptr;
	
	ptr = strtok(str, "!, ");

	while(ptr != NULL){
		cout << ptr << std::endl;
		ptr = strtok(NULL, "!, ");
	}

	return 0;
}