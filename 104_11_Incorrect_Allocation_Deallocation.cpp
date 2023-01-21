#include <iostream>

int main() {
int* p1 = new int;
delete p1; // correct
// delete[] p1; // undefined
// free(p1); // undefined
int* p2 = new int[10];
delete[] p2; // correct
// delete p2; // undefined
// free(p2); // undefined
int* p3 = static_cast<int*>(malloc(sizeof(int)));
free(p3); // correct
// delete p3; // undefined
// delete[] p3; // undefined
}