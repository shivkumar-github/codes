/*
Playing with character arrays and pointers
*/

#include <iostream>
using namespace std;

int main()
{

    // int arr[] = {1, 2, 7, 9};
    // char arr1[] = "abcde";

    // cout<< arr << endl; // it prints the address
    // cout<< arr1 << endl; // it gives the content in the char array
    // // i.e. cout have different implementation on character array and integer array

    // char temp = 'z';
    // char* charptr = &temp;
    // cout<< charptr << endl; // here cout will print all the characters from temp untill it encounters a null character \0

    char charArray[4] = "hey"; // one extra space for null character
    // cout<< sizeof(charArray) << endl; // size of 1 character is 1 byte
    // cout<< sizeof(charArray[0]) << endl;

    // char* ch = "abcde"; // ->> not acceptable
    // cout<< ch << endl;
    // when we initialise an array the content  for example in case of charArray hey will be stored in a temporary memory and will be pointed by charArray pointer 

    // char charArray2[3] = {'h', 'e', 'y'};
    // cout<< sizeof(charArray2) << endl;
    // cout<< sizeof(charArray2[0]) << endl;

    return 0;
}