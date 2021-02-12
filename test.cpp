#include <stdio.h>

int F(int v[], int n)
{
	if(n == 0) return v[0];
	else
		if(v[n] < 0) return F(v, n-1);
		else return v[n]+F(v, n-1);
}
int main()
{
	int i, n, v[10000];

	scanf("%d", &n);
	for(i = 0; i < n; i++)
		if(i%2 == 0) v[i] = 2*i;
		else v[i] = -i;
	printf("%d", F(v, n-1));
	return 0;
}
