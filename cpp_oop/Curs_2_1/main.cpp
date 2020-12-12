#include <iostream>
#include"Produs.h"
#include <fstream>

using namespace std;

int main()
{
    /*
    //se apeleaza constructorul fara argumente
    Produs p1;
    p1.afisare();

    Produs p2("Cafea", 4.4, 100);
    p2.afisare();
    */
    Produs tp[10];
    for(int i =0; i<10; i++)
        tp[i].afisare();

    ifstream fin("produse.in");
    char den[30];
    double pret;
    int stoc, i=0;

    while(fin>>den>>pret>>stoc)
{
    tp[i].setDenumire(den);
    tp[i].setPretUnitar(pret);
    tp[i].setStoc(stoc);
    i++;

}

cout << "........................................" <<endl<< endl;
for(int i=0; i<10;i++)
{
    tp[i].afisare();
}

    ofstream fout("valoareStoc.csv");
    for(int j=0; j<i; j++)
    fout<<tp[j].getDenumire()<<","<<(tp[j].getPretUnitar()*tp[j].getStoc())<<endl;
    fout.close();

    Produs *ob = new Produs();
    ob->afisare();

    delete ob;

    Produs ob1, ob2, ob3;

    return 0;
}
