#include<iostream>		//QUICK SORT

#include<fstream>
using namespace std;
ifstream in("date.in");
void citire();
void afisare();
void qsort(int s,int d);

int n,a[20];		//n-nr. de elemente, a-vectorul care conþine ºirul

int main()
{citire();
 qsort(0,n-1);
 afisare();
 return 0;
}
void citire()				//tire datelor
{int i;
 in>>n;
 for (i=0;i<n;i++)
  in>>a[i];
}

void afisare()				//iºarea datelor
{int i;
 for(i=0;i<n;i++)
   cout<<a[i]<<" ";
 cout<<endl;
}


void qsort(int s,int d)	//s-indicele din stânga intervalului, d-indicele din dreapta intervalului
{int aux,m,i,j;		//aux-variabilã auxiliarã pentru interschimbarea elementelor, ind. de mijloc
  if (s<d)			//dacã mai existã elemente în ºir
   { m=a[(s+d)/2]; 		//determinãm elementul din mijlocul ºirului
     i=s;     j=d;			//i-indice, parcurge subºirul stâng de la stânga la dreapta
     do				// j-indice, parcurge subºirul drept de la  dreapta la stânga
     {while ((i<=d) && (a[i]<m))  	//cât timp elementele din stg. sunt în ordinea doritã
           i++;				// creºte i
       while ((j>=s) && (a[j]>m))             //cât timp elementele din dr. sunt în ordinea doritã
           j--;				// scade j
       if (i<=j)                  //dacã mai sunt elemente în subsiruri, ele nu sunt în orinea doritã
        {aux=a[i];		//le inversãm
         a[i]=a[j];
         a[j]=aux;
         i++;  j--;		//creºte i ºi scade j
        }
     }
    while (i<=j);		//se repetã algoritmul cât timp mai sunt elemente între i ºi j
    qsort(s,j);		// se reia algoritmul pe subºirul stâng
    qsort(i,d);		// se reia algoritmul pe subºirul drept
  }
}
