#include <iostream>

using namespace std;

class ContBancar
{
    char titular[50];
    char numarCont[30];
    double sold;

public:
    void depunere(double suma)
    {
        sold+=suma;
    }

    void retragere(double suma)
    {
        sold-=suma;
    }

    void afisare()
    {
        cout<<titular<< " " << numarCont << " " << sold << endl;
    }
};

class Student {char nume[50]; ..};
    Student s1;
    s1.init("Popescu");
    Student s2;
    s2.init("Ionescu");


int main()
{
    int x,y;
    cout << x << y << endl;
    return 0;
}
