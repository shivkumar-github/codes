// the Dutch National flag algorithm
// three pointer approach
#include <bits/stdc++.h>
using namespace std;

void printArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void sort012(int arr[], int n)
{
	// divide array into three parts (at last the array must have indices mid low high such that 0 to low -1 will contain  all 0s and low to mid-1 will contain all 1s and mid to high-1 will contain all 2s)
	// first will have all 0 second all 1 and third all 2
	// consider the arr is the unsorted part of array as shown in image
	// hence start the low from where the 1s begin in sorted array mid from start of unsorted part and high from end of the unsorted part i.e. end of our arr
	int low = 0;
	int mid = 0;
	int high = n - 1;
	while (mid <= high)
	{
		if (arr[mid] == 0) swap(arr[mid++], arr[low++]); // no need to check element at mid again as the left part is already sorted  
		else if (arr[mid] == 1) mid++; // increament mid
		else if (arr[mid] == 2)
		{
			swap(arr[mid], arr[high--]); // don't increament mid before checking new element at mid
			if (arr[mid] == 0) swap(arr[mid++], arr[low++]); // if it is 0 then swap it with low and then increase mid (else if arr[mid] after swapping is two then keep mid as it is)
		}
	}
}

int main()
{
	int arr[] = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	// int arr[] = {0, 1, 2, 0, 0, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << n << endl;
	sort012(arr, n);
	printArr(arr, n);
	return 0;
}