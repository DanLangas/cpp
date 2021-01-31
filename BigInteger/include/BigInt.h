#ifndef BIGINT_H
#define BIGINT_H
#define LGMAX 100000
#include <iostream>

using namespace std;

class BigInt
{
    private:
        char cifre[LGMAX]; //vectorul de cifre
        int lg;            //lungimea numarului
    public:
        //constructori
        BigInt(int n=0); //constructor care creeaza numarul mare dintr-un numar intreg
        BigInt(const char * s); //constructor care creeaza numarul mare dintr-un sir
        BigInt(BigInt&); //constructorul de copiere
        int GetLg() { return lg; }

        friend bool e0(const BigInt &);

        //operatorul de atribuire
        BigInt& operator = (const BigInt &);

        //operator de indexare
        int operator [] (const int) const;
        BigInt& operator++();  //forma prefixata
        BigInt operator++ (int fictiv); //forma postfixata
        BigInt& operator--(); //forma prefixata
        BigInt operator--(int fictiv); //forma postfixata

        friend BigInt operator +(const BigInt &, const BigInt &);
        friend BigInt& operator +=(BigInt &, const BigInt &);

        friend BigInt operator -(const BigInt &, const BigInt &);
        friend BigInt& operator -=(BigInt &, const  BigInt &);

        friend BigInt operator *(const BigInt &, const BigInt &);
        friend BigInt& operator *=(BigInt &, const BigInt &);

        friend BigInt operator /(const BigInt &, const BigInt &);
        friend BigInt& operator /=(BigInt &, const BigInt &);

        friend BigInt operator %(const BigInt &, const BigInt &);
        friend BigInt& operator %=(BigInt &, const BigInt &);

        //operatori de egalitate
        friend bool operator == (const BigInt &, const BigInt &);
        friend bool operator != (const BigInt &, const BigInt &);

        //operatori relationali
        friend bool operator < (const BigInt &, const BigInt &);
        friend bool operator <= (const BigInt &, const BigInt &);
        friend bool operator > (const BigInt &, const BigInt &);
        friend bool operator >= (const BigInt &, const BigInt &);

        //operatori de citire/scriere
        friend ostream & operator <<(ostream &, const BigInt &);
        friend istream & operator >>(istream &, BigInt &);
};


#endif // BIGINT_H
