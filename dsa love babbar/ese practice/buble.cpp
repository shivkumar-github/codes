/*
in bubble sort we swap smaller element
in ith round it last ith maximum element is placed at it's position
selection mein sabse chhota har bar uski position pr (ek swap mein) rakhte hai
bubble mein har ek swap karke sabse bada uski position mein rakhte hai

*/

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr)
{
        for (int i = 0; i < arr.size(); i++)
        {
                cout << arr[i] << " ";
        }
        cout << endl;
}

void bubbleSort(vector<int> &arr,int size)
{
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
                for (int j = 0; j < n - i - 1; j++)
                        if (arr[j + 1] < arr[j]) // standard condition for all sorting
                                swap(arr[j + 1], arr[j]);
        }
}

int main()
{
        vector<int> array = {14, 10, 9, 7, 6, 1};
        bubbleSort(array, array.size());
        print(array);
        return 0;
}