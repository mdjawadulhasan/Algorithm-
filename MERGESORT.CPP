#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right, int size)
{
    int left_index = left;
    int right_index = mid + 1;
    int new_index = left;

    int temp[size];

    while (left_index <= mid && right_index <= right)
    {

        if (arr[left_index] <= arr[right_index])
        {
            temp[new_index] = arr[left_index];
            left_index++;
            new_index++;
        }
        else
        {
            temp[new_index] = arr[right_index];
            right_index++;
            new_index++;
        }
    }

    while (left_index <= mid)
    {
        temp[new_index] = arr[left_index];
        left_index++;
        new_index++;
    }
    while (right_index <= right)
    {
        temp[new_index] = arr[right_index];
        right_index++;
        new_index++;
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right, int size)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        merge(arr, left, mid, right, size);
    }
    else
    {
        return;
    }
}

int main()
{
    cout << "Enter size of array: " << endl;
    int size;
    cin >> size;
    int myarray[size];

    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> myarray[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;
    mergeSort(myarray, 0, (size - 1), size);

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}





///////////////////////
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right, int size)
{
    int i, j, k = left;

    int temp[size];

    for (i = left, j = (mid + 1); i <= mid && j <= right;)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right, int size)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        merge(arr, left, mid, right, size);
    }
    else
    {
        return;
    }
}

int main()
{
    cout << "Enter size of array: " << endl;
    int size;
    cin >> size;
    int myarray[size];

    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> myarray[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }
    cout << endl;
    mergeSort(myarray, 0, (size - 1), size);

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << myarray[i] << " ";
    }

    return 0;
}