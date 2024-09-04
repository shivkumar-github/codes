/*
Leet Code
https://leetcode.com/problems/reverse-words-in-a-string/

151. Reverse Words in a String
Medium
7.8K
5K
Companies
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Constraints:

1 <= s.size <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.


Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // to return reverse of temp which will be a valid word
    string returnReverse(string &temp)
    {
        int start = 0;
        int end = temp.size() - 1;
        while (start <= end)
        {
            swap(temp[start++], temp[end--]);
        }
        return temp;
    }

    // function to check if a valid char
    bool isValidChar(char ch)
    {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
    }

    // actual function
    string reverseWords(string s)
    {

        string ans = "";
        int i = s.size() - 1;
        while (i >= 0)
        {
            string temp = "";             // is it neccessary to initialise it blank
            while (s[i] != ' ' && i >= 0) // store the cahracters untill you encoutner a space and each time i>= 0
            {
                temp.push_back(s[i]);
                i--;
            }
            // also have to do i-- when we encounter blank space
            i--;
            // to handle multiple spaces
            while (!isValidChar(s[i])) // or s[i] == ' '
            {
                i--;
            }

            // then store reverse of that string which will be a word in the final ans
            // if the word being entered is first word then do not enter with space
            if (ans.empty())
            {
                ans += returnReverse(temp);
            }
            // else include space
            else
            {
                ans += " " + returnReverse(temp); // we can not use push_back because it is used to insert single characters only
            }
        }
        return ans;
    }
};

int main()
{
    // cout << var; -> ascii value of space = 32 --> not useful
    string input = "";
    cout << "Enter the string : " << endl;
    getline(cin, input);

    Solution S1;
    string ans = S1.reverseWords(input);
    cout << ans << endl;

    return 0;
}