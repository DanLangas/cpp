#include <iostream>
using namespace std;


// Definition of user-defined function doJob()

void doJob() // doJob is the called function in this example
{
	cout << "In doJob() function \n";
}

// Definition of function main()
int main()
{
	cout << "Starting main function \n";
	doJob(); // doJob() called for the first time
	doJob(); // doJob() called for the second time
	cout << "Ending main() function for multiple calls\n";

	return 0;
}

