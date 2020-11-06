#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cout << "Introduceti 3 numere intregi";

/* care citeste de la tastatura 3 intregi astfel incat,
 * dupa introducerea de la tastatura a valorilor 3, 4 si 5 sa afiseze:
 * Dublul sumei numerelor plus 6 este 30 */ 
	cin >> a; cin >> b; cin >> c;
	cout << "Dublul sumei numerelor plus 6 este: " << 2*(a +b +c) + 6 << endl; 

	return 0;
}
