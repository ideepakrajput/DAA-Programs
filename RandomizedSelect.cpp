#include <iostream>
using namespace std;
int RandomizedPartition(int A[], int p, int r)
{
    int temp;
    int s = rand() % r;
    int x = A[s];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    return i;
}

int RandomizedSelect(int A[], int p, int r, int i)
{
    if (p == r)
    {
        return A[p];
    }
    int q = RandomizedPartition(A, p, r);
    int k = q - p + 1;

    if (i == k)
        return A[q];
    else if (i < k)
        return RandomizedSelect(A, p, q - 1, i);
    else
        return RandomizedSelect(A, q + 1, r, i - k);
}
void printArray(int ar[], int l)
{
    for (int i = 0; i < l; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n, i;
    cout << "Enter the number of elements in array :- ";
    cin >> n;
    int A[n];
    cout << "Enter the elements of array :- ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "\n------------: Given array is :------------ \n";
    printArray(A, n);
    int p = 0;
    int r = n - 1;
    cout << "\nThe position for which highest element need to be found :- ";
    cin >> i;
    int element = RandomizedSelect(A, p, r, i);
    cout << "\nThe " << i << "(st/rd/th) largest element is " << element << endl;
    return 0;
}