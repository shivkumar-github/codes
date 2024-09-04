/*
https://www.codingninjas.com/studio/problems/check-if-the-string-is-a-palindrome_1062633
Problem statement
You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :

String 'S' is NOT case sensitive.
Example :

Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.
*/
/*
also present on leetcode
https://leetcode.com/problems/valid-palindrome/
*/
#include <iostream>
#include <string>
using namespace std;

char returnLowerCase(char &ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool toIgnore(char &ch)
{
    return !((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90) || (ch > '0' && ch < '9'));
}

bool checkPalindrome(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}

bool isPalindrome(string s)
{
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (!toIgnore(s[i]))
        {
            temp.push_back(s[i]);
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        temp[i] = returnLowerCase(temp[i]);
    }
    return checkPalindrome(temp);
}

int main()
{
    // char arr[1000];
    // cin.get(arr,1000);

    string s;
    cout << "Enter your string : " << endl;
    getline(cin, s);
    cout << s << endl;
    cout << "is a palindrome : " << checkPalindrome(s);

    return 0;
}