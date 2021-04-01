#include <iostream>
using namespace std;

void CountingSort(int Input_Ar[], int size, int r)
{
    int Output_Ar[size + 1];
    int Count_Ar[r];

    for (int i = 0; i < r; i++)
        Count_Ar[i] = 0;

    for (int i = 0; i < size; i++)
        Count_Ar[Input_Ar[i]]++;

    for (int i = 1; i < r; i++)
        Count_Ar[i] = Count_Ar[i] + Count_Ar[i - 1];

    for (int i = 0; i < size; i++)
    {

        Output_Ar[Count_Ar[Input_Ar[i]]] = Input_Ar[i];
        Count_Ar[Input_Ar[i]]--;
    }

    for (int i = 0, pp = 1; i < size; i++)
    {
        Input_Ar[i] = Output_Ar[pp];
        pp++;
    }
}

int main()
{
    int size;
    int range = 10;
    cout << "Enter Size of array: " << endl;
    cin >> size;
    int myarray[size];

    cout << "Enter " << size << " integers in any order in range of 0-9: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> myarray[i];
    }

    CountingSort(myarray, size, range); // counting sort called
    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    return 0;
}