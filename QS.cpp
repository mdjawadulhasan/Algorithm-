#include <bits/stdc++.h>
using namespace std;

int Partition(char arr[], int start, int end)
{
    char pivot = arr[end];
    int pi = start;

    for (int i = start; i < end; i++)
    {
        if (arr[i] >= pivot)
        {
            swap(arr[i], arr[pi]);
            pi++;
        }
    }

    swap(arr[end], arr[pi]);
    return pi;
}

void Quick_Sort(char arr[], int start, int end)
{
    if (start < end)
    {
        int p = Partition(arr, start, end);
        Quick_Sort(arr, start, (p - 1));
        Quick_Sort(arr, p + 1, end);
    }
}

int main()
{
    int size;
    cout << "String Size:";
    cin >> size;
    char arr[size];
    int flag = 1;

    cout << "Enter the Character:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            cout << "Invalid Input" << endl;
            flag = 0;
            break;
        }
    }

    if (flag == 1)
    {
        Quick_Sort(arr, 0, (size - 1));
        cout << "\nSorted Array:";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
    }

    return 0;
}
