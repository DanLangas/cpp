#include <iostream>
#include"Produs.h"
#include<string.h>

using namespace std;

Produs::Produs()
{
    strcpy(denumire, "###");
    pretUnitar = 0.0;
    stoc =0;
    cout << "Constuctor fara argumente " << endl;
}

Produs::Produs(char *denumire, double pretUnitar, int stoc)
{
    strcpy(this->denumire,denumire);
    this->pretUnitar = pretUnitar;
    this->stoc=stoc;
    cout<<"Costructor cu argumente"<<endl;
}

void Produs::afisare()
{
       cout<<denumire<<""<<pretUnitar<<" "<<stoc<<endl;
}
double Produs::pretTVA()
{
        return pretUnitar*1.19;
}

void Produs::setDenumire(char *v)
{
    strcpy(denumire,v);
}

void Produs::setPretUnitar(double v)
{
    pretUnitar = v;
}
void Produs::setStoc(int v)
{
    stoc = v;
}

char* Produs::getDenumire()
{
    return denumire;
}
double Produs::getPretUnitar()
{
    return pretUnitar;
}
int Produs::getStoc()
{
    return stoc;
}

Produs::~Produs()
{

    cout<<"Destructor"<<endl;
}


