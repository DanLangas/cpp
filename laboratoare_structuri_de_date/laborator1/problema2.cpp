#include <iostream>
using namespace std;



int main () {
    int x[10];
    int n;
    cin >> n;
        for (int i=0; i<n; i++)
            cin >> x[i];
        // afisare vector
        for (int i=0; i<n; i++)
        {
            cout << x[i];
            if(i<n-1) cout  << ", ";

        }
    cout << endl;;

    int s=0;
    for (int i=0; i<n; i++)
        s+=x[i];
    cout << "Suma este" << s << endl;

   return 0;
}

