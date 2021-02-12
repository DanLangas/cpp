#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t length = 30;

int main()
{
    ofstream fout("danrandom.txt", ios::out);

    srand(time(NULL));

    int r;
    for (size_t i = 0; i < length; i++)
    {
        r = rand();
        fout.write((char*)&r, sizeof(r));
    }

    fout.close();
    return 0;
}
