// new and delete keywords in C++
#include <iostream>
using namespace std;

int main()
{
    // basic example
    int a = 4;
    int *ptr = &a;
    cout << *(ptr) << endl;

    // new keyword
    // new keyword returns pointer to the allocated memory
    float *p = new float(8);
    cout << *(p) << endl;
    delete p;
    int *arr = new int[4];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 1010;
    arr[3] = 40;

    // delete operator
    delete[] arr; // we have to use the [] after delete keyword to delete an array
    cout << "The value of arr[0] is : " << arr[0] << endl;
    cout << "The value of arr[1] is : " << arr[1] << endl;
    cout << "The value of arr[2] is : " << arr[2] << endl;
    cout << "The value of arr[3] is : " << arr[3] << endl;
    cout << "The value of arr[2] is : " << *(arr) << endl;
    cout << "The value of arr[2] is : " << *(arr + 1) << endl;
    cout << "The value of arr[2] is : " << *(arr + 2) << endl;
    cout << "The value of arr[3] is : " << *(arr + 3) << endl;
    // the values of arr[2] and arr[3] are getting correctly printed ..
    // But this is not guaranteed and can change with different runs of the program, different compilers, or different systems.

    return 0;
}