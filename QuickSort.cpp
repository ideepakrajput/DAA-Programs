#include <iostream>
using namespace std;
int comp = 0;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int partition(int ar[], int p, int r)
{
    int x = ar[r];
    int i = p - 1;
    for (int j = p; j <= (r - 1); j++)
    {
        if (ar[j] <= x)
        {
            i = i + 1;
            int temp = ar[j];
            ar[j] = ar[i];
            ar[i] = temp;
        }
    }
    int temp = ar[r];
    ar[r] = ar[i + 1];
    ar[i + 1] = temp;
    return (i + 1);
}
void quickSort(int ar[], int p, int r)
{
    int q;
    comp++;
    if (p < r)
    {
        q = partition(ar, p, r);
        quickSort(ar, p, q - 1);
        quickSort(ar, q + 1, r);
    }
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

    quickSort(ar, 0, n - 1);

    cout << "\n------------: The number of comparisons in sorting :------------ \n";
    cout << comp;

    cout << "\n------------: Sorted Array is :------------ \n";
    printArray(ar, n);
    return 0;
}