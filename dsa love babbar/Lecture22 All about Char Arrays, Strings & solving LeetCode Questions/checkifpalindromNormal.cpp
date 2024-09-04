/*
checking if a normal c-string is a palindrome or not
*/

#include <iostream> 
#include<string>
using namespace std;

bool checkPalindrome(char input[], int n)
{
    // if we create an array reverse that of s and then compare if both are equal it will take more memory space(due to creation of another reversed array)
    for (int i = 0; i < n/2; i++)
    {
        if (input[i] != input[n-1-i])
        { 
            cout << i << endl;
            return 0;
        }
        
    }
    return 1;
}

int main(){
    char arr1[] = "hi";
    char arr2[] = "yooy";
    cout << "for arr1 -> " << checkPalindrome(arr1,2) << endl;
    cout << "for arr2 -> " << checkPalindrome(arr2,4) << endl;
    return 0;
}