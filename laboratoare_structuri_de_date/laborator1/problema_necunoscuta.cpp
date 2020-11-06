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
        int x[10], n;
        creareLista(x, n);
        afisareLista(x, n);
        cout << "Suma elementelor este: " << sumaElemente(x, n) << endl;

    return 0;

}


