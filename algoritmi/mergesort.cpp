#include <iostream>		//SORTARE PRIN INTERCLSARE
#define MAX 20
using namespace std;
int a[MAX],tmp[MAX], n;

void citire();
void afisare();
void MergeSort(int v[], int st, int dr);

int main()
{int i;
 citire();
 afisare();
 MergeSort(a,0,n-1);

 afisare();

 return 0;
}
void citire()		// citeºte n ºi elementele ºirului
{int i;
 cout<<"n=";cin>>n;
 for(i=0;i<n;i++)
   {cout<<"a["<<i<<"]="; cin>>a[i]; }
}
void afisare()			//afiºeaza elementele ºirului
{int i;
 for(i=0;i<n;i++)
    cout<<a[i]<<" ";
 cout<<endl;
}


void MergeSort(int v[], int st, int dr)
{
	if(st < dr)
	{
		int m = (st + dr) / 2;
		MergeSort(v, st , m);
		MergeSort(v, m + 1 , dr);

		int i = st, j = m + 1, k = 1;
		while( i <= m && j <= dr )
			if( v[i] < v[j])
				tmp[k++] = v[i++];
			else
				tmp[k++] = v[j++];
		while(i <= m)
			tmp[k++] = v[i++];
		while(j <= dr)
			tmp[k++] = v[j++];
		for(i = st , j = 1 ; i <= dr ; i ++ , j ++)
			v[i] = tmp[j];
	}
}
