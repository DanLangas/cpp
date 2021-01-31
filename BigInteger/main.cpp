#include <iostream>
#include <BigInt.h>

using namespace std;

int main()
{
    BigInt n, m, p, r, k, q;
    cout<<"Initializam primul numar lung n, cu n="<<n<<"; Introduceti primul numar lung:"<<endl;
    cin>>n;
    cout<<"Initializam al doilea numar lung m, cu m="<<m<<"; Introduceti al doilea numar lung:"<<endl;
    cin>>m;
    p=n+m;
    cout<<"Suma cu operatorul + pentru aceste numere este:"<<p<<endl;
    r=n-m;
    cout<<"Diferenta cu operatorul - pentru aceste numere este: "<<r<<endl;
    k=n*m;
    cout<<"Inmultirea cu operatorul * este:"<<k<<endl;
    q=n/m;
    cout<<"Impartirea cu operatorul / este:"<<q<<endl;
    return 0;
}
