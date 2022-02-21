#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

// IMPORTANT LIBRARIES TO PLOT GRAPH
// THE FUCNTION DEFINITION FOR PLOTTING GRAPH IS AT THE END
#include "pbPlots.hpp"
#include "supportLib.hpp"

using namespace std;

int t;

// HEAP SORT FUNCTION
void heapify(int arr[], int n, int i)
{
	// Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	t++;
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Heap sort
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		// Heapify root element to get highest element at root again
		heapify(arr, i, 0);
	}
}
// FUNCTION DECLARATION

void compare();
void plotGraph(vector<double> arraySize, vector<double> comparisons, vector<double> nlogn);

// MAIN FUNCTION

int main()
{

	compare();
}

// FUNCTION TO CALCULATE COMPARISIONS
void compare()
{
	fstream output1;
	fstream comparisons;
	comparisons.open("comparisons.txt", ios::out);

	comparisons << setw(20) << "Array Size"
				<< "\t" << setw(20) << "comparisons" << setw(20) << "n log(n)";
	comparisons << endl;

	vector<double> arraySize;
	vector<double> compArray;
	vector<double> nlogn;

	output1.open("heapSort.txt", ios::out);
	if (!output1)
	{
		cout << "File Not Created/\n";
	}
	else
	{
		cout << "File Created Successfully\n";

		for (int p = 0; p < 100; p++)
		{

			output1 << "TEST CASE " << p + 1 << endl
					<< endl;
			t = 0;

			int i, k;
			do
			{
				k = rand();
			} while (k < 30 || k > 1000);

			int a[k];

			for (int h = 0; h < k; h++)
			{
				a[h] = rand();
			}

			output1 << endl;
			output1 << "LENGTH OF ARRAY IS = " << k;
			arraySize.push_back(k);

			heapSort(a, k - 1);

			// Printing the sorted data.
			int l = 0;

			output1 << "\n\nSorted Data \n";
			for (i = 0; i < k; i++)
			{

				output1 << setw(15) << a[i];
				l++;
				if (l == 10)
				{
					output1 << endl;
					l = 0;
				}
			}
			output1 << "\n\n NO. OF COMPARISONS IS = " << t;
			compArray.push_back(t);
			output1 << "\n\n\n\n\n";
		}
	}

	int key, keyComp, j;
	for (int i = 1; i < 100; i++)
	{
		key = arraySize[i];
		keyComp = compArray[i];
		j = i;
		while (j > 0 && arraySize[j - 1] > key)
		{
			arraySize[j] = arraySize[j - 1];
			compArray[j] = compArray[j - 1];
			j--;
		}
		arraySize[j] = key;
		compArray[j] = keyComp;
	}

	for (int i = 0; i < 100; i++)
	{
		comparisons << setw(20) << arraySize[i] << setw(20) << compArray[i] << setw(20) << arraySize[i] * (log(arraySize[i])) << endl;
	}

	for (int i = 0; i < 100; i++)
	{
		nlogn.push_back(arraySize[i] * log(arraySize[i]));
	}

	plotGraph(arraySize, compArray, nlogn);
}

// GRAPH PLOTTING

void plotGraph(vector<double> arraySize, vector<double> compArray, vector<double> nlogn)
{
	bool success;
	StringReference *errorMessage = new StringReference();

	RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

	ScatterPlotSeries *series = GetDefaultScatterPlotSeriesSettings();
	series->xs = &arraySize;
	series->ys = &compArray;
	series->linearInterpolation = true;
	series->pointType = toVector(L"solid");
	series->lineThickness = 2;
	series->color = CreateRGBColor(1, 0, 0);

	ScatterPlotSeries *series2 = GetDefaultScatterPlotSeriesSettings();
	series2->xs = &arraySize;
	series2->ys = &nlogn;
	series2->linearInterpolation = true;
	series2->pointType = toVector(L"solid");
	series2->lineThickness = 2;
	series2->color = CreateRGBColor(0, 0, 1);

	ScatterPlotSettings *settings = GetDefaultScatterPlotSettings();
	settings->width = 1600;
	settings->height = 900;
	settings->autoBoundaries = true;
	settings->autoPadding = true;
	settings->title = toVector(L"");
	settings->xLabel = toVector(L"");
	settings->yLabel = toVector(L"");
	settings->scatterPlotSeries->push_back(series);
	settings->scatterPlotSeries->push_back(series2);

	success = DrawScatterPlotFromSettings(imageReference, settings, errorMessage);
	if (success)
	{
		vector<double> *pngdata = ConvertToPNG(imageReference->image);
		WriteToFile(pngdata, "heapSort.png");
		DeleteImage(imageReference->image);
	}
	else
	{
		cerr << "Error: ";
		for (wchar_t c : *errorMessage->string)
		{
			wcerr << c;
		}
		cerr << endl;
	}
}