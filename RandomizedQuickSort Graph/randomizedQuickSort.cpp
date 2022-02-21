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

// RANDOMZIED QUICK SORT FUNCTION
int partition(int arr[], int low, int high)
{
	// pivot
	int pivot = arr[high];

	// Index of smaller element
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller
		// than or equal to pivot
		if (arr[j] <= pivot)
		{

			// increment index of
			// smaller element
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
	// Generate a random number in between
	// low .. high
	srand(time(NULL));
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high]
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}

/* The main function that implements
QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	t++;
	if (low < high)
	{

		/* pi is partitioning index,
		arr[p] is now
		at right place */
		int pi = partition_r(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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

	output1.open("output1.txt", ios::out);
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

			quickSort(a, 0, k - 1);

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
		WriteToFile(pngdata, "plot.png");
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