/*

*/

#include <iostream>
#include <vector>
using namespace std;

// time complexity = O(n^2)
vector<int> seletection(vector<int> arr)
{
	// in selection sort we start
	for (int i = 0; i < arr.size(); i++)
	{

		int minInd = i;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[minInd] < arr[j])
				minInd = j;
		}
		if (minInd != i)
			swap(arr[i], arr[minInd]);
	}
	return arr;
}

// partition function
int partition(vector<int> &arr, int s, int e)
{
	// it is our choice to decide pivot element
	int pivot = arr[s];
	int cnt = 0;
	// counting elements smaller than pivot element
	for (int i = s + 1; i < e; i++)
	{
		if (arr[i] < pivot)
		{
			cnt++;
		}
	}
	// calculating pivot index
	int pivotInd = s + cnt;
	// placing pivot element at it's position
	swap(arr[s], arr[pivotInd]);
	int i = s;
	int j = e;
	while (i < pivotInd && j > pivotInd)
	{
		// iterate till you find element greater than pivot in the left part
		while (arr[i] < pivot)
		{
			i++;
		}
		// iterate till you find smaller element than the pivot in the right part
		while (arr[j] >= pivot)
		{
			j++;
		}
		// swapping those elements
		if (i < pivotInd && j > pivotInd)
		{
			swap(arr[i], arr[j]);
		}
	}
	return pivotInd;
}

void quick(vector<int> &arr, int s, int e)
{
	if (s >= e)
		return arr;
	// find partition index
	int p = partition(arr, s, e);
	// sort left part
	quick(arr, s, p - 1);
	// sort right part
	quick(arr, p + 1, e);
}

void merge(vector<int> &arr, int s, int e)
{
	int mid = s + (e - s) / 2;
	int len1 = mid + 1 - s;
	int len2 = e - mid;
	vector<int> arr1(len1);
	vector<int> arr2(len2);
	for (int i = 0; i < len1; i++)
	{
		arr1[i] = arr[i];
	}
	for (int i = 0; i < len2; i++)
	{
		arr2[i] = arr[i + len1];
	}
	int i = 0;
	int j = 0;
	int mainArInd = 0;
	while (i < len1 && j < len2)
	{
		if (arr1[i] > arr2[j])
		{
			arr[mainArInd++] = arr2[j++];
		}
		else
		{
			arr[mainArInd++] = arr1[i++];
		}
	}
	while (i < len1)
	{
		arr[mainArInd++] = arr1[i++];
	}
	while (j < len2)
	{
		arr[mainArInd++] = arr2[j++];
	}
}

void mergeSort(vector<int> &arr, int s, int e)
{
	if (s <= e)
		return arr;
	int mid = s + (e - s) / 2;
	mergeSort(arr, s, mid);
	mergeSort(arr, mid + 1, e);
	merge(arr, s, e);
}

vector<int> bubble(vector<int> arr)
{
	int n = arr.size();
	// the largest elements “bubbling” to the top
	for (int i = 0; i < n - 1; i++)
	{
		bool swapped = false;
		for (int j = i; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		// if not swapped once that means every element after an element is greater than that element i.e. array is already sorted
		if (!swapped)
			break;
	}
	return arr;
}

vector<int> insertion(vector<int> arr)
{
	// in this sort we select a element and check the part of array present before it (which is sorted already in it's own)
	// and till the elements are greater than selected element we shift the array towrds right
	// and then after finding a smaller element then the position of selected element is after that element
	for (int i = 1; i < arr.size(); i++)
	{
		int j = i - 1;
		int temp = arr[i];
		for (; j >= 0; j--)
		{
			if (temp < arr[j])
				arr[j + 1] = arr[j];
			else
				break;
		}
		// after completing the loop the j will be on the first smaller element than the selected one hence
		arr[j + 1] = temp;
	}
	return arr;
}

int main()
{
	vector<int> arr = { 1,
						66,
						77,
						2,
						900,
						23,
						101 } return 0;
}