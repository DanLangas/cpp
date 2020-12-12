#include <iostream>
#include <cmath.h>
using namespace std;

class Punct
{
    double x;
    double y;

public:
    void init(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    void afisare()
    {
       // cout << x<<" " << y<<endl;
       cout << this->x<< " " << this->y<<endl;
    }

    double distanta(Punct ob1, Punct ob2)
    {
        return sqrt((ob1.x - ob2.x)*(ob1.x - o2.x)=(ob1.y - ob2-y)*(o1.y - ob2.y));
    }
};

int main()
{

    Punct ob1, ob2;
    ob1.init(1,2);
    ob2.init(3,4);

    cout <<
return 0;
}
