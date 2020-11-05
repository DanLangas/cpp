#include <iostream>
using namespace std;



int main()
{
	cout << "Enter first integer: ";
	int num_first{ 0 };
	cin >> num_first;
	
	cout << "Enter second integer: ";
	int num_second{ 0 };
	cin >> num_second;

	cout << "The sum of numbers is: " << num_first + num_second << '\n'; 
	cout << "The substraction of the two numbers is: " << num_first - num_second << '\n';

	return 0;
}
