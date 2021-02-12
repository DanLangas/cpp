#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

long length = 1000;
const long max_length = 300000;

int list[max_length];

void read()
{
    ifstream fin("random.dat", ios::binary);
    for (long i = 0; i < length; i++)
    {
        fin.read((char*)&list[i], sizeof(int));
    }
    fin.close();
}

void bubbleSort()
{
    int temp;
    for(long i = 0; i < length; i++)
    {
        for(long j = 0; j < length-i-1; j++)
        {
            if (list[j] > list[j+1])
            {
                temp        = list[j];
                list[j]     = list[j+1];
                list[j+1]   = temp;
            }
        }
    }
}

void insertionSort()
{
    int temp;
    for(long i = 1; i < length; i++)
    {
        temp = list[i];
        long j;
        for(j = i-1; j >= 0 && list[j] > temp; j--)
        {
            list[j+1] = list[j];
        }
        list[j+1] = temp;
    }
}

long partition(long left, long right)
{
    int pivot_element = list[left];
    int lb = left, ub = right;
    int temp;

    while (left < right)
    {
        while(list[left] <= pivot_element)
            left++;
        while(list[right] > pivot_element)
            right--;
        if (left < right)
        {
            temp        = list[left];
            list[left]  = list[right];
            list[right] = temp;
        }
    }
    list[lb] = list[right];
    list[right] = pivot_element;
    return right;
}

void quickSort(long left, long right)
{
    if (left < right)
    {
        long pivot = partition(left, right);
        quickSort(left, pivot-1);
        quickSort(pivot+1, right);
    }
}

int main()
{
    double t1, t2;

    for (length = 1000; length <= max_length; )
    {
        cout << "\nLength\t: " << length << '\n';

        read();
        t1 = clock();
        bubbleSort();
        t2 = clock();
        cout << "Bubble Sort\t: " << (t2 - t1)/CLK_TCK << " sec\n";

        read();
        t1 = clock();
        insertionSort();
        t2 = clock();
        cout << "Insertion Sort\t: " << (t2 - t1)/CLK_TCK << " sec\n";

        read();
        t1 = clock();
        quickSort(0, length - 1);
        t2 = clock();
        cout << "Quick Sort\t: " << (t2 - t1)/CLK_TCK << " sec\n";

        switch (length)
        {
        case 1000 :
            length = 5000;
            break;
        case 5000 :
            length = 10000;
            break;
 /*       case 10000 :
            length = 50000;
            break;
        case 50000 :
            length = 100000;
            break;
        case 100000 :
            length = 200000;
            break;
        case 200000 :
            length = 300000;
            break;
        case 300000 :
            length = 300001;
            break; */
        }
    }

    return 0;
}
