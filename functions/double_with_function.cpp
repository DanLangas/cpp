#include <iostream>
using namespace std;


int getValueFromUser() // this function returns an integer value
{
	cout << " Enter an integer:" ;
	int usr_input{};
	cin >> usr_input;

	return usr_input;
}

int main()
{
	int num { getValueFromUser() }; // initialize num with the return value of getValueFromUser()

	cout << num << " double is: " << num * 2 << '\n';

	return 0;
}
