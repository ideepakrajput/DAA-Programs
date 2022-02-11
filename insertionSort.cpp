#include <iostream>
using namespace std;
void printArray(int ar[], int l)
{
    for (int i = 0; i < l; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
void insertionSort(int ar[], int l)
{
    int comp = 0;
    for (int i = 1; i < l; i++)
    {
        cout << "\nPass :- " << i << endl;
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = key;
        printArray(ar, l);
        comp++;
    }
    cout << "\nTotal comparision :- " << comp << endl;
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
    insertionSort(ar, n);
    cout << "\n------------: Sorted Array is :------------ \n";
    printArray(ar, n);
    return 0;
}