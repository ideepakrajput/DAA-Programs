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
int getMax(int ar[], int n)
{
    int max = ar[0];
    for (int i = 0; i < n; i++)
    {
        if (ar[1] > max)
        {
            max = ar[i];
        }
    }
    return max;
}
void CountSort(int A[], int B[], int Al, int k)
{
    int C[k];
    for (int i = 0; i < k; i++)
    {
        C[i] = 0;
    }

    for (int j = 0; j < Al; j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }

    for (int i = 1; i < k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = Al - 1; j >= 0; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements in array :- ";
    cin >> n;
    int A[n];
    int B[n];
    int max = getMax(A, n);
    cout << "Enter the elements of array :- ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "\n------------: Given array is :------------ \n";
    printArray(A, n);
    CountSort(A, B, n, max);
    printArray(B, n);
    return 0;
}