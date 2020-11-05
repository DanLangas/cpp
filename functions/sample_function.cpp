#include <iostream>
using namespace std;


// Definition of user-defined function doPrint()
//

void doPrint() // doPrint is the called function in this example
{
	cout << "In doPrint() function \n";
}

// Definition of function main()
int main(){
	cout << "Starting main function \n";
	doPrint();
	cout << "Ending main() function \n";

	return 0;
}

