#include <iostream>
using namespace std;

void doB()
{
	cout << "  In doB() function\n";
}

void doA()
{
	cout << " Starting doA function\n";
	doB();
	cout << "Ending  doA() function\n";
}

//  Definition of  main()  function

int main()
{
	cout<< "Staring main()\n";
		doA();
	cout<<"Ending main() functionn";

	return 0;
}

