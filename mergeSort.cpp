#include <iostream>
using namespace std;
int count = 0;
int merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
        count++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(int arr[], int l, int r)
{
    int comparisons;
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        comparisons = merge(arr, l, m, r);
    }
    return comparisons;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in array :- ";
    cin >> n;
    int ar[n];
    cout << "Enter the elements of array :- ";
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    cout << "\n------------: Given array is :------------ \n";
    printArray(ar, n);

    int c = mergeSort(ar, 0, n - 1);

    cout << "\n------------: Sorted Array is :------------ \n";
    printArray(ar, n);
    cout << "\n------------: The number of comparisons in sorting :------------ \n";
    cout << c;

    return 0;
}