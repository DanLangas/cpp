#include <iostream>
#include <chrono> // for high_resolution_clock
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t length = 30000000;

int main()
{
    // Record start time
auto start = std::chrono::high_resolution_clock::now();

// Portion of code to be timed
   ofstream fout("danrandom.txt", ios::out);

    srand(time(NULL));

    int r;
    for (size_t i = 0; i < length; i++)
    {
        r = rand();
        fout.write((char*)&r, sizeof(r));
    }

    fout.close();

// Record end time
auto finish = std::chrono::high_resolution_clock::now();

std::chrono::duration<double> elapsed = finish - start;

std::cout << "Elapsed time: " << elapsed.count() << " s\n";
return 0;
}
