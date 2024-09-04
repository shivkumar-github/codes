/*
 pointers in C++
 coding ninjas theory
 https://www.codingninjas.com/studio/guided-paths/pointers/content/235645/offering/3168907

 symbol table is an important data structure created and maintained bt compiler to store different information about code
 In this symbol table the variable is mapped with an memory address whenever the variables name is used the value at that memory location is used

Note: The asterisk (*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier) and should not be confused with the dereference operator seen above, but which is also written with an asterisk (*). They are simply two different things represented with the same sign.

*/

// #include <iostream>
// using namespace std;

// int* func(){
//     int x = 10;
//     return &x;
// }

// int main()
// {
    /*
    int num = 5;

    cout << num << endl;

    // address of operator
    cout<< "Address of num is : " << &num << endl;
     // address = 0x61ff0c ->> for example is in hexadecimal form

    int *ptr = & num;
    cout<< *ptr << endl;

    double d = 4.3;
    double* p2 = &d;

cout<< "size of pointer to an integer is: " << sizeof(ptr) << endl;
cout<< "size of pointer to a double is: " << sizeof(p2)<< endl;
cout<< "size of double variable is: " << sizeof(d) << endl;
// address of pointer variable to every variable is same as though the data stored in pointer variable is an address for pointer of any type of variable
// hence size of pointer variable to any data type is same.


    int *ptr1 = 0;
    cout<< *ptr1 << endl; // gives segmentation fault
    */

    // int num = 7;
    // void *ptr;
    // ptr = &num;                // ->> void pointers giving error
    // cout<<int*(ptr) << endl;
    // (*ptr)++; // braces are neccessary
    // cout << num << endl;

    // int** ptr1 = &ptr;
    // cout<< ptr << endl << ptr1 << endl;
    
    // cout<< "now num = " << *ptr1  << endl << *ptr << endl << num << endl;

    // cout<< ptr << endl;
    // cout<< &ptr << endl;
    // ptr = ptr + 1;
    // now ptr = ptr + sizeof(int) // for example 0x61ff04 -> 0x61ff08
    // cout<< ptr << endl;
    // cout<< "size of pointer to pointer variable is: " << sizeof(ptr1) << endl;


    // int* ptr = func();
    // cout<< "*ptr" << *ptr << endl; // ->> dangling pointer
    // the pointer that points to a memory location that points to a memory which deleted or freed


    // char* ptr;

    // cout<< "hey there" << endl;
    // {
    //     char ch = 'a';
    //     ptr = &ch;
    // }
    // cout<< "hey there" << endl;
    // cout << *ptr << endl;





    // return 0;
// }




/*
a interesting problem from coding ninjas
*/

#include<iostream>
using namespace std;

void square(int* ptr){
    int a = 10;
    ptr = &a;
    *ptr = *(ptr) * *(ptr);
}

int main(){
int a = 10;
square(&a);
cout<< a << endl; // a will remain 10 
return 0;
}