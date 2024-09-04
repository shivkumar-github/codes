/*
Introduction to reference variables
*/

#include <iostream>
using namespace std;

/*
void update(int &n)
{
    n = n + 1;
}

int main()
{
    int num = 5;
    int &x = num;
    int y = x;
    update(y);
    cout << num << endl;
    cout<< y << endl;
    return 0;
}
    */

int& badPractice(int n){
    int ans = n;
    return ans;

// warning: reference to local variable 'ans' returned
// the memory assigned for variable ans will be deleted or allocated to another operation as soon as the block of this function ends
// i.e. we are trying to access a memory which is already deleted or may be now assigned to some any other operation 
// hence it is a bad practice

    // // but we can return as
    // static int staticVar = 23;
    // staticVar++; // every time we call the function the value of staticVar will be increamented by 1
    // return staticVar;
} // warning: reference to local variable 'ans' returned
// the memory assigned for variable ans will be deleted or allocated to another operation as soon as the block of this function ends
// i.e. we are trying to access a memory which is already deleted or may be now assigned to some any other operation 
// hence it is a bad practice

int* pointerReturnBadPractice(int num){
    int* ptr = &num;
    return ptr;
}

int main(){

    int num = 90;
    int num1 = badPractice(num);
    // cout<< num1 << endl; // ->> 24
    // num1 = badPractice(num);
    // num1 = badPractice(num);
    // cout<< num1 << endl; // ->> 26

    pointerReturnBadPractice(num);
    


    return 0;
}