#include <iostream> // for std:: cout and std:: cin
using namespace std;


int main()
{
	cout << "Enter a number: "; // ask user for a number
	int x{}; // define variable x to hold user input ( and zero initialize it )
	cin >> x; // get number from keyboard and store it in variable x
	cout << "You entered " << x << '\n';
	return 0;
}
