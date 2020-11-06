#include <iostream> 
using namespace std; 

const int N=100;

	int GetInput()
{
	int choice;
	cin >> choice;
	return choice;
}

	void DisplayMenu()
{
         cout << "1 - Introducere lista de la tastatura.\n";
	 cout << "2 - Afisare lista pe ecran. \n";
         cout << "3 - Stergere element din lista.\n";
         cout << "4 - Inserare element in lista.\n";
         cout << "5 - Afisare element din lista corespunzator pozitiei specificate.\n";
         cout << "6 - Modificare element din lista.\n";
}

void creareLista(int x[], int &n) 
{ 
	cout << "Introduceti dimensiunea listei:\n ";
	cin >> n; 
	for (int i = 0; i < n; i++) 
	cin >> x[i]; 
} 

void afisareLista(int x[], int n) 
{ 
	cout << "Elementele listei sunt:\n ";
	for (int i = 0; i < n; i++) 
        cout << x[i] << ", "; 
	cout << endl;
} 

void stergereElem(int x[], int& n, int k)
{
	if (n == 0)
	{
        cout << "UNDERFLOW\n";
        return;

	}
		if (k < 0 || k >= n)
	{
        cout << k << " A fost introdusa o pozitie invalida.\n";
        return;
	}	
	int m = x[k];
	for (int i = k; i < n - 1; i++)
	{
        x[i] = x[i + 1];

	}
    n = n - 1;
    cout << m << "A fost sters\n";

}

void inserareElem(int x[], int& n, int k, int a)
{
	if (k < 0 || k > n)
	{
        cout << k << "A fost introdusa o pozitie invalida.\n";
        return;
	}

    for (int i = n + 1; i >= k + 1; i--)
        x[i] = x[i - 1];
	x[k] = a;
	n = n + 1;
}

void afisareElem(int x[], int& n, int k)
{
	if (k < 0 || k >= n)
    {
	cout << k << " A fost introdusa o  pozitie invalida.\n";
        return;

    }

    cout << x[k];

}

void modificareElem(int x[], int& n, int k, int a)
{
    if (k < 0 || k >= n)
{
        cout << k << " A fost introdusa o pozitie invalida.\n";
        return;
    }
    x[k] = a;
}

int sumaElemente(int x[], int n)
{ 
	int suma = 0;
	for (int i = 0; i < n; i++) 
	suma += x[i];
	return suma;

} 

int main(int argc, char *argv[])
{
	
	 int x[N], n, k, p, a, r, d, b;
         int choice = 0;

         do
         {
            DisplayMenu();
            choice = GetInput();
            switch(choice) {
                    case 1:
                            creareLista(x, n);
                            break;
                    case 2:
                            afisareLista(x, n);
                            break;
                    case 3:
            		    cout << "Sterge elementul de pe pozitia: \n"; cin >> k; stergereElem(x, n, k);
                            break;
		    case 4:
			    cout << "Se insereaza elementul:\n'";  cin >> a;
            		    cout << "Pozitia elementului va fi: \n"; cin >> p;
            		    inserareElem(x, n, p, a);
                            break;
		    case 5:
            		    cout << "Acceseaza elementul de pe pozitia: \n"; cin >> r;
                            afisareElem(x, n, r);
                            break;
		    case 6:
                            cout << "Se modifica elementul de pe pozitia: \n"; cin >> d;
                            cout << "Noua valoare a elementului va fi:\n "; cin >> b;
                            modificareElem(x, n, d, b);
                            break;

                    default:
                            return 0;
                   }
           } while(true);
       
     }



