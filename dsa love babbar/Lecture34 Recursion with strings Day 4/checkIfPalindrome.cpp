/*
check if a string is palindrome or not using recursion
*/

#include <iostream>
using namespace std;

bool isPalindrome(string str, int s, int e)
{
    // base case
    if (s >= e)
    {
        return true;
    }
    if (str[s++] != str[e--])
    {
        return false;
    }
    else
    {
        // recursive call
        return isPalindrome(str, s, e);
    }
}

int main()
{
    string str = "abbccbba";
    bool ans;
   ans = isPalindrome(str, 0, str.length() - 1);
    cout << "It is " << (ans ? "" : "not ") << "a palindrome." << endl;
    return 0;
}