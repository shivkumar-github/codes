//arrays and pointers

#include <iostream>
using namespace std;

int main()
{   //it is a good practice to start from '0' when you are dealing with arrays and strings
    int marks[4] = {34, 45, 66, 67}; // no need to define size as cpp compiler detects the size automatically when we are entering elements while declaration
    // also in cpp counting starts from 0
    cout << marks[0] << endl;
    cout << marks[1] << endl;
    cout << marks[2] << endl;
    cout << marks[3] << endl;

    int mathmarks[4];
    mathmarks[0] = 750;
    mathmarks[1] = 950;
    mathmarks[2] = 50;
    mathmarks[3] = 70;
    cout << "These are the math marks :" << endl;
    cout << mathmarks[0] << endl;
    cout << mathmarks[1] << endl;
    cout << mathmarks[2] << endl;
    cout << mathmarks[3] << endl;

    // you can change the value of an array just like a normal variable

    // printing values of elements in array using loop

    // for loop
    for (int i; i < 4; i++)
    {
        cout << "The value of mark is " << mathmarks[i] << endl;
    }

    // similarly we can do this by using while and do while loop

    // C++ pointers and arrays
    //  address of first block/element of an array is it's name also &marks is wrong method

    // pointer arithmetic :-
    // address(new) = address(current) + i * sizeof(data type of which the array is made)  ....jab 'i' se poiner ki value badhai gayi ho

    int *p = marks; //  as &math[0] = math
    cout << "The value of *p is " << *p << endl;
    cout << "The value of *(p+1) is " << *(p + 1) << endl; // always use braces to avoid confusion
    cout << "The value of *(p+2) is " << *(p + 2) << endl; // dereferencing pointer
    cout << "The value of *(p+3) is " << *(p + 3) << endl;

    cout << *(p++) << endl;
    cout << *(++p) << endl;

    return 0;
}
//difference between string and arrays //extra theory
//1.elements in string can not be changed easily but we can change elements of array
/* Array element can not be initialized selectively. To initialize
second location is illegal. For e.g. int a[5]={ ,2} is illegal*/
