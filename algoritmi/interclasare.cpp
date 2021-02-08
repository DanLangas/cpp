#include <iostream>
#include <fstream>
#define MAX 50
using namespace std;

ifstream in("date.in");
int a[MAX],n;

void citire()
{
    in>>n;
    for(int i=1;i<=n;i++)
        in>>a[i];

}

void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void interclasare(int li,int ls,int m, int a[])
{
    int b[MAX],i=li,j=m+1,k=1;
    while(i<=m && j<=ls)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)
        b[k++]=a[i++];
    while(j<=ls)
       b[k++]=a[j++];

    k=1;
    for(i=li;i<=ls;i++)
        {a[i]=b[k];k++;}

}

void sortare(int li,int ls,int a[])
{
    int aux;
    if(a[li]>a[ls])
    {
        aux=a[li]; a[li]=a[ls]; a[ls]=aux;
    }
}

void div_imp(int li,int ls,int a[MAX])
{ int m;
    if((ls-li)<=1)
        sortare(li,ls,a);
    else
    {
        m=(li+ls)/2;
        div_imp(li,m,a);
        div_imp(m+1,ls,a);
        interclasare(li,ls,m,a);
    }
}
int main()
{
    citire(); afisare();
    div_imp(1,n,a);
    afisare();
    return 0;
}
