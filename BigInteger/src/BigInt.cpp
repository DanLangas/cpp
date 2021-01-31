#include "BigInt.h"
#include <cstring>

BigInt::BigInt(int n)
{//initializez cu 0 vectorul de cifre
    memset(cifre,0, LGMAX);
    //extrag cifrele lui n si le memorez incepand cu unitatile
    lg=0;
    do
        {
            cifre[lg]=n%10;
            n/=10;
            lg++;
            }
            while(n);
}

BigInt::BigInt(const char* s)
{
    memset(cifre,0,LGMAX);
    lg=strlen(s);
    if (lg)
        for (int i=lg-1; i>=0; i--)
    {
         if (s[i]>='0'&&s[i]<='9');
            cifre[lg-i-1]=s[i]-'0';
    }
    else lg=1;
}

BigInt::BigInt(BigInt& ob)
{
    int i;
    lg=ob.lg;
    memset(cifre, 0, LGMAX);
    for (i=0;i<lg;i++)
        cifre[i]=ob.cifre[i];
}

bool e0(const BigInt & ob)
{
    return ob.lg==1 && ob.cifre[0]==0;
}

BigInt& BigInt::operator = (const BigInt & ob)
{
    int i;
    if (this != &ob)
    {
        lg=ob.lg;
        memset (cifre,0,LGMAX);
        for (i=0;i<lg;i++) cifre[i]=ob.cifre[i];
    }
    return *this;
}

int BigInt::operator [] (const int poz) const
{
    if (poz<0 || poz>LGMAX-1);
    return cifre[poz];
}

BigInt& BigInt::operator++()
{
    int i;
    for (i=0;i<lg && cifre[i]==9; i++) cifre[i]=0;
    cifre[i]++;
    if (i==lg) lg++;
}

BigInt BigInt::operator++(int fictiv)
{
    BigInt temp;
    temp = *this;
    ++(*this);
    return temp;
}

BigInt& BigInt::operator--()
{
    int i;
    for (i=0; cifre[i]==0; i++) cifre[i]=9;
    cifre[i]--;
    if (lg>1 && cifre[lg-1]==0) lg--;
}

BigInt BigInt::operator--(int fictiv)
{
    BigInt temp;
    temp = *this;
    --(*this);
    return temp;
}

bool operator == (const BigInt & ob1, const BigInt & ob2)
{
    int i;
    if (ob1.lg!=ob2.lg) return false;
    for (i=0;i<ob1.lg && ob1.cifre[i]==ob2.cifre[i]; i++);
    return i==ob1.lg;
}

bool operator != (const BigInt & ob1, const BigInt & ob2)
{
    return !(ob1==ob2);
}


bool operator < (const BigInt &ob1, const BigInt &ob2)
{
    int i;
    if (ob1.lg < ob2.lg) return true;
    if (ob1.lg > ob2.lg) return false;
    for (i=ob1.lg-1; i>=0 && ob1.cifre[i]==ob2.cifre[i];i--);
    if (i==-1) return false;
    if (ob1.cifre[i]<ob2.cifre[i]) return true;
    return false;
}

bool operator > (const BigInt &ob1, const BigInt &ob2)
{
    return ob2<ob1;
}

bool operator <= (const BigInt &ob1, const BigInt &ob2)
{
    return !(ob1>ob2);
}

bool operator >= (const BigInt &ob1, const BigInt &ob2)
{
    return !(ob1<ob2);
}



BigInt& operator+= (BigInt &ob1, const BigInt &ob2)
{
        int t=0, s, i;
            if (ob2.lg>ob1.lg) ob1.lg=ob2.lg;
            for (i=0; i<ob1.lg; i++)
            {
                s=ob1.cifre[i]+ob2.cifre[i]+t;
                t=s/10;
                ob1.cifre[i]=s%10;
            }
            if (t)
            {

                if (ob1.lg==LGMAX);
                ob1.cifre[ob1.lg++]=t;
            }
            return ob1;
}
BigInt operator +(const BigInt &ob1, const BigInt &ob2)
{
    BigInt temp;
    temp=ob1; temp+=ob2;
    return temp;
}

BigInt& operator-=(BigInt &ob1, const BigInt &ob2)
{
    int i, t=0, s;
    for (i=0; i<ob1.lg; i++)
    {
        s=ob1.cifre[i]-ob2.cifre[i]+t;
        if (s<0) {s+=10; t=-1;}
        else t=0;
        ob1.cifre[i]=s;
    }
    while (ob1.lg>1 && ob1.cifre[ob1.lg-1]==0) ob1.lg--;
    return ob1;
}

BigInt operator-(const BigInt &ob1, const BigInt &ob2)
{
    BigInt temp;
    temp=ob1; temp-=ob2;
    return temp;
}

BigInt& operator *= (BigInt & ob1, const BigInt & ob2)
{
    int v[LGMAX];
    int i, j, t, s;
    memset(v, 0, sizeof(int)*LGMAX);
    if (e0(ob1) || e0(ob2))
    {
         ob1=BigInt();
         return ob1;
    }
    for (i=0; i<ob1.lg; i++)
        for (j=0; j<ob2.lg; j++)
    {

        v[i+j]+=ob1.cifre[i]*ob2.cifre[j];
    }
    for (t=i=0; i<LGMAX; i++)
    {
        s=t+v[i];
        v[i]=s%10;
    }
    for (ob1.lg=LGMAX; ob1.lg>1 && !v[ob1.lg-1]; ob1.lg--);
    for (i=0; i<ob1.lg;i++) ob1.cifre[i]=v[i];
    return ob1;
}

BigInt operator *(const BigInt & ob1, const BigInt & ob2)
{
    BigInt temp;
    temp=ob1; temp*=ob2;
    return temp;
}

BigInt& operator /= (BigInt & ob1, const BigInt & ob2)
{
    int cat[LGMAX], i, lgcat=0, cc;
    if (ob1<ob2)
        {
            ob1=BigInt(); return ob1;
        }
    if (ob1==ob2)
    {
        ob1=BigInt(1); return ob1;
    }
    BigInt t;
    for (i=ob1.lg-1; t*10+ob1.cifre[i]<ob2; i--)
    {
        t*=10+ob1.cifre[i];
        for (cc=9; cc*ob2>t; cc--);
        t-=cc*ob2;
        cat[lgcat++]=cc;
    }
    ob1.lg=lgcat;
    for (i=0; i<lgcat; i++) ob1.cifre[i]=cat[lgcat-1-i];
    return ob1;
}

BigInt operator /(const BigInt & ob1, const BigInt & ob2)
{
    BigInt temp;
    temp = ob1; temp/=ob2;
    return temp;
}

BigInt& operator %= (BigInt & ob1, const BigInt & ob2)
{
    int cat[LGMAX], i, lgcat=0, cc;
    if (ob1<ob2)
    {
        return ob1;
    }
    if (ob1==ob2)
    {
        ob1=BigInt();
        return ob1;
    }
    BigInt t;
    for (i=ob1.lg-1; t*10+ob1.cifre[i]<ob2; i--)
    {
        t*=10; t+=ob1.cifre[i];
    }
    for(; i>=0; i--)
    {
        t=t*10+ob1.cifre[i];
        for (cc=9; cc*ob2>t; cc--);
        t-=cc*ob2;
        cat[lgcat++]=cc;
    }
    while (t.lg>1 && t.cifre[t.lg-1]==0) t.lg--;
    ob1=t;
    return ob1;
}

BigInt operator %(const BigInt & ob1, const BigInt & ob2)
{
    BigInt temp;
    temp=ob1; temp%=ob2;
    return temp;
}

istream & operator >> (istream &in, BigInt & ob)
{
    char s[LGMAX+1];
    in>>s;
    ob.lg=strlen(s);
    for (int i=ob.lg-1; i>=0; i--)
        ob.cifre[ob.lg-i-1]=s[i]-'0';
    return in;
}

ostream & operator << (ostream & out, const BigInt & ob)
{
    for (int i=ob.lg-1; i>=0; i--)
        out<<(int)ob.cifre[i];
    return out;
}
