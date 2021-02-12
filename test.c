#include <iostream>

using namspace std;


 int F(int n)
{
if (n==0) return 0;
else
  	if (n%10 > F(n/10)) return n%10;
  	else return F(n/10);
}

int main(){
int x=34823;
cout << F(x)<<endl;
 return 0;
