#include <iostream>
using std::cout;

template <typename T> // A simple class to hold one number of any type
class Number
{
public:
	void setNum(T n); // Sets the class field to the given number
	T plus1() const;  // returns class field's "follower"
private:
	T num; // Class field
};

template <typename T> // Set the class field to the given number
void Number<T>::setNum(T n)
{
	num = n;
}

template <typename T> // returns class field's "follower"
T Number<T>::plus1() const
{
	return num + 1;
}

int main()
{
	Number<int> anInt; // Test with an integer (int replaces T in the class)
	anInt.setNum(1);
	cout << "My integer + 1 is " << anInt.plus1() << "\n"; // Prints 2

	Number<double> aDouble;								   // Test with a double
	aDouble.setNum(3.1415926535897);
	cout << "My double + 1 is " << aDouble.plus1() << "\n"; // Prints 4.14159
	
	Number<float> aFloat;									// Test with a float
	aFloat.setNum(1.4);
	cout << "My float + 1 is " << aFloat.plus1() << "\n"; // Prints 2.4
	return 0;											  // Successful completion

}