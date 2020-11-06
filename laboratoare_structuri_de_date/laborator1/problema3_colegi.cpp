#include <iostream> 

using namespace std; 

 

const int N = 100; 

 

void creareLista(int x[], int& n) 

{ 

    cout << "Introduceti dimensiunea listei: " << endl; 

    cin >> n; 

    cout << "Scrieti elementele listei: " << endl; 

    for (int i = 0; i < n; i++) 

        cin >> x[i]; 

} 

 

void afisareLista(int x[], int n) 

{ 

    for (int i = 0; i < n; i++) 

        cout << x[i] << " "; 

    cout << endl; 

 

} 

 

void inserareElem(int x[], int& n, int k, int a) 

{ 

    if (k < 0 || k > n) 

    { 

        cout << k << " este pozitie invalida." << endl; 

        return; 

    } 

    for (int i = n + 1; i >= k + 1; i--) 

        x[i] = x[i - 1]; 

    x[k] = a; 

    n = n + 1; 

} 

 

void accesareElem(int x[], int& n, int k) 

{ 

    if (k < 0 || k >= n) 

    { 

        cout << k << " este pozitie invalida." << endl; 

        return; 

    } 

    cout << x[k] << endl; 

} 

 

void modificareElem(int x[], int& n, int k, int a) 

{ 

    if (k < 0 || k >= n) 

    { 

        cout << k << " este pozitie invalida." << endl; 

        return; 

    } 

    x[k] = a; 

} 

 

 

void stergereElem(int x[], int& n, int k) 

{ 

    if (n == 0) 

    { 

        cout << "Underflow" << endl; 

        return; 

    } 

    if (k < 0 || k >= n) 

    { 

        cout << k << " este pozitie invalida." << endl; 

        return; 

    } 

    int aux = x[k]; 

    for (int i = k; i < n - 1; i++) 

    { 

        x[i] = x[i + 1]; 

    } 

    n = n - 1; 

    cout << "A fost stearsa valoarea " << aux << endl; 

} 

 

int main() 

{ 

    int x[N], n = 0; 

    int operatie; 

 

    while (true) 

    { 

        cout << "Introduceti 1 pentru creare lista." << endl; 

        cout << "Introduceti 2 pentru afisare lista." << endl; 

        cout << "Introduceti 3 pentru stergere element." << endl; 

        cout << "Introduceti 4 pentru inserare element." << endl; 

        cout << "Introduceti 5 pentru accesare element." << endl; 

        cout << "Introduceti 6 pentru modificare element." << endl; 

        cout << "Optiunea aleasa: "; 

        cin >> operatie; 

        if (operatie != 1 && n == 0) 

        { 

            cout << "Pentru a putea face acesta operatie, mai intai trebuie creata lista." << endl; 

            continue; 

        } 

        switch (operatie) 

        { 

        case 1: 

            creareLista(x, n); 

            break; 

        case 2: 

            afisareLista(x, n); 

            break; 

        case 3: 

            cout << "Sterge elementul de pe pozitia: " << endl; 

            int k; 

            cin >> k; 

            stergereElem(x, n, k); 

            break; 

 

 

 

        case 4: 

            int p, a; 

            cout << "Insereaza elementul: " << endl; 

            cin >> a; 

            cout << "Pozitia elementului va fi: " << endl; 

            cin >> p; 

            inserareElem(x, n, p, a); 

            break; 

 

        case 5: 

            int r; 

            cout << "Acceseaza elementul de pe pozitia: " << endl; 

            cin >> r; 

            accesareElem(x, n, r); 

            break; 

 

        case 6: 

            int d, b; 

            cout << "Modifica elementul de pe pozitia: " << endl; 

            cin >> d; 

            cout << "Noua valoare a elementului va fi: " << endl; 

            cin >> b; 

            modificareElem(x, n, d, b); 

            break; 

 

        default: 

            return 0; 

        } 

    } 

    return 0; 

} 

 
