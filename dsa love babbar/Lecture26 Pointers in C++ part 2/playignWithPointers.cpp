/*
Playing with pointers
*/

#include <iostream>
using namespace std;

int main()
{

    // char arr1[] = "hey there";
    // int num = 7;
    // cout<< &arr1[0] << endl; ->> doubt
    // cout<< &num << endl;

    // char arr[] = "yo bro";
    // char *ptr = &arr[0];
    // cout << "arr->" << &arr[0] << endl;
    // cout << "ptr->" << ptr << endl;
/*
    int arr[] = {1, 6, 10, 16, 76};
    int i = 3;
    cout << i[arr] << endl;
    // arr[i]= i[arr] = *(arr +i) both are executed in same way
    cout << 2[arr] << endl;*/
  
    // double temp[10];
    // cout<< sizeof(temp) << endl;

    // double * ptr = &temp[0];
    // cout<< sizeof(ptr) << endl; // size of address
    // cout<< sizeof(*ptr) << endl; // size of double variable
    // cout<< sizeof(&ptr) << endl; // ->> size of a address
    
    
    int a[20];
    // a = a + 1; // a is not a modifyable value 
    //            // will create an ERROR
    int* ptr = &a[0];
    ptr++;
    cout<< ptr << endl;







    return 0;
}