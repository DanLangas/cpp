#include <iostream> 
using namespace std; 

const int N=100;

void creareLista(int x[], int &n) // apelare prin referinta
{ 
// n se modifica in functie si se pastreaza valoarea la iesirea din functie
	cout << "Introduceti dimensiunea listei: ";
	cin >> n; 
	for (int i = 0; i < n; i++) 
	cin >> x[i]; 
} 

void afisareLista(int x[], int n) 
{ 
	for (int i = 0; i < n; i++) 
        cout << x[i] << ", "; 
	cout << endl;
} 

int sumaElemente(int x[], int n)
{ 
	int suma = 0;
	for (int i = 0; i < n; i++) 
	suma += x[i]; 
	
	return suma; 

} 

int main()
{ 
	int x[N], n;
	int operatie;

while (true)

{
	cout << "Introduceti 1 pentru citire lista." << endl ;

	cout << "Introduceti 2 pentru afisare lista." << endl;

	cout << "Introduceti 3 pentru stergere element." << endl;

	cout << "Optiunea aleasa: ";

	cin >> operatie; //Optiunea aleasa

	switch (operatie) //selectare operatie
{

 case 1: creareLista(x, n);

 break;

 case 2: afisareLista(x, n);
	break;





	default:

	return 0;

}
}
    return 0; 

}
