/*
    =>  learning char arrays and c strings
    ->  if a c string is "heu" then it's length while creating should be 4 (to include the null character)
    ->  '\0' null charcter has ascii value 0
    ->  cout stops after encountering null character
    ->  and cin ends it's operation on encountering space or new line
    ->

    => A little bit about C++ strings 
    -> std :: string stores its data in the form of null-terminated c string but, in normal usage it does not allows you to access the null terminator
    -> you may check cplusplus.com to know more about functions on C ++ string s
*/

#include <iostream>
using namespace std;

int returnarrLen(char *arr)
{
    int count = 0;
    for (; arr[count] != '\0'; count++)
    {
    }
    return count;
}

// Leet Code problem link
// https://leetcode.com/problems/reverse-string/description/
void reversArray(char *arr, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(arr[start++], arr[end--]);
    }
    // for(int i = 0;i < s.size()/2 ; i++){
    //     swap(s[i],s[s.size()-1-i]);
    // }
    // why the second approach is taking less time on leetcode
}

int main()
{
    char name[20];
    cout << "Enter your name : ";
    cin >> name;
    cout << "Your name is : " << name << endl;

    cout << name << endl;

    // size of array
    cout << "Size of array : " << returnarrLen(name) << endl;

    // reversing the array
    reversArray(name, 9);
    cout << name << endl;

    // // c type strings can also be declared as
    // const char* hello ;    // after this type of declaration string can not be modified later
    // hello = "hello";                                // used when we want to make a string which shouldn't be changed ;
    // cout << hello << endl;
    // hello = "world";
    // cout << hello << endl; ===> very confusing added by me

    // char hey[] ="hey";
    // cout << hey << endl;
    // *hey = 'i';
    // cout << hey << endl;
    
    return 0;
}