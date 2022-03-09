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

void countingSort(int array[], int size, int place)
{
    const int max = getMax(array, size);
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixSort(int array[], int size)
{
    int max = getMax(array, size);

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

int main()
{
    int n;
    cout << "Enter the number of elements in array :- ";
    cin >> n;
    int A[n];
    int max = getMax(A, n);
    cout << "Enter the elements of array :- ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "\n------------: Given array is :------------ \n";
    printArray(A, n);
    radixSort(A, n);
    cout << "\n------------: Sorted Array is :------------ \n";
    printArray(A, n);
    return 0;
}