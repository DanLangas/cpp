#include <iostream>
using namespace std;


void returnNothing()
{
	cout << "Hello" << '\n';
	// this function does not return a value so no return statement is needed
}

int main()
{
	returnNothing(); // function is called, no value is returned
//	cout << returnNothing(); // expect error, let's see at compilation ---> yes, a lot of garbage, let's comment this

	return 0;
}
	
