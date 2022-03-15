#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void BucketSort(double *arr, int n)
{
    vector<double> bucket[n];
    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i];
        bucket[index].push_back(arr[i]);
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            arr[k] = bucket[i][j];
            k++;
        }
    }
}
void printArray(double ar[], int l)
{
    for (int i = 0; i < l; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of elements in array :- ";
    cin >> n;
    double A[n];
    cout << "Enter the elements of array :- ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "\n------------: Given array is :------------ \n";
    printArray(A, n);
    BucketSort(A, n);
    cout << "\n------------: Sorted Array is :------------ \n";
    printArray(A, n);
    return 0;
}