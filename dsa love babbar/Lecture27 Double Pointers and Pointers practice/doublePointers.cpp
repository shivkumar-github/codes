/*
Say hello to double pointers
*/

#include <iostream>
using namespace std;

void update(int **ptrToptr)
{
    // Identify which of the following will change the value of i in the main function

    // will this change anything ? ->> no any of the statement will not change the value of i 
    // ptrToptr = ptrToptr + 1; 

    // will this change anything ?
    *ptrToptr = *ptrToptr + 1;

    // will this change anything ?
    **ptrToptr = **ptrToptr + 1;
}

int main()
{
    int i = 5;
    int *ptr = &i;
    int **ptrToptr = &ptr; // int* -> data type of varialbe that we want to store and next * to show that it is a pointer

    // // accessing the main element i in different ways
    // cout << "i = " << **ptrToptr << endl;
    // cout << "i = " << *ptr << endl;
    // cout << "i = " << i << endl;

    // // accessing the second element that is adress of i
    // cout << "ptr = " << &i << endl;
    // cout << "ptr = " << ptr << endl;
    // cout << "ptr = " << *ptrToptr << endl;

    // // accessing the third element i.e. address of ptr i.e. ptrToptr
    // cout << "ptrToptr = " << &ptr << endl;
    // cout << "ptrToptr = " << ptrToptr << endl;


    // updation function understanding 
    cout<< "Values before update are : " << endl;
    cout<< "i = " << i << endl;
    cout<< "ptr = " << ptr << endl;
    cout<< "ptrToptr = " << ptrToptr << endl;
    update(ptrToptr);
    cout<< "Values after update are : " << endl;
    cout<< "i = " << i << endl;
    cout<< "ptr = " << ptr << endl;
    cout<< "ptrToptr = " << ptrToptr << endl;

    

    return 0;
}