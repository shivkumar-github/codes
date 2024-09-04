/*
pointers and functions
*/

#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void updatep(int *p)
{
    // p = p + 1;
    // cout<< "in the function " << p << endl;
    // pointer in main can not be updated from here 


    // but the value stored at memory pointed by pointer can be updtate

    // correct
    // *p = *p + 1;
    (*p)++;

    // // incorrect
    // *p++;
    // *(p++);


}


void passingArray(int* arr, int n){
    cout<< endl << "Size : " << sizeof(arr) << endl; // will print the size of pointer arr and not the size of whole array
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    // return sum;    
}

/*
using pointers we can pass a part of array using pointers
*/

int main()
{

    // int value = 5;
    // int *p = &value;
    // // print(p);

    // // cout<< "before " << p << endl;
    // updatep(p);
    // // cout<< "after " << p << endl;
    // cout<< *p << endl;


    int arr[4] = {1, 2, 3, 4};
    // cout << passingArray(arr, 4) << endl; 
    passingArray(arr,4);







    return 0;
}