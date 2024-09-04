/*
Leet Code problem
https://leetcode.com/problems/permutation-in-string/
567. Permutation in String
Medium
10.9K
370
Companies
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* approach =>
first we have to create a window of size equal to size of first string
then we will traverse through the second string in the window of size equl to s1
if no of each alphabet in first string is equal to number of any window in second string then return true
for more detail see lecture AT 1:26:51
*/
class Solution
{
public:
    vector<int> CharCountOfString(string str)
    {
        vector<int> ans(26, 0);
        for (int i = 0; i < str.size(); i++)
        {
            char ch = str[i];
            int indexOfChar = ch - 'a';
            ans[indexOfChar]++;
        }
        return ans;
    }

    //     bool checkIfPermutation(string s1, string s2)
    //     {
    // vector<int> CharCountOfString1 = CharCountOfString(s1); // computing and storing once so that avoid recalculation every time
    // int n = s2.size() - s1.size(); //why ?
    //         for (int i = 0; i <= (n); i++)
    //         {
    //             string window;
    //             // cout <<"ehy";
    //             for (int K = 0; K < s1.size(); K++)
    //             {
    //                 window.push_back(s2[i + K]);
    //             }
    //             if (CharCountOfString1 == CharCountOfString(window)) // we can check like this if two vectors are equal
    //             {
    //                 return true;
    //             }
    //         }
    //         return false;
    //     } ==> more time complexity therefore taking much time

    // approach by babbar -> have less time complexity
    bool checkIfPermutation(string s1, string s2)
    {
        vector<int> CharCountOfString1 = CharCountOfString(s1);
        vector<int> CharCountOfWindow(26, 0);

        int windowSize = s1.length();
        // creating first window
        int i = 0;
        while (i < windowSize && i < s2.length()) //=>i<s2.length() for case when s1 has more length than s2
        {
            CharCountOfWindow[s2[i] - 'a']++;
            i++;
        }

        // window ko aage badao
        while (i < s2.length())
        {
            char newChar = s2[i];
            CharCountOfWindow[newChar - 'a']++;
            char oldChar = s2[i - windowSize];
            CharCountOfWindow[oldChar - 'a']--;
            i++;
            if (CharCountOfString1 == CharCountOfWindow)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    string s1, s2;
    cout << "Enter first string : " << endl;
    getline(cin, s1);
    cout << "Enter second string : " << endl;
    getline(cin, s2);
    Solution S1;
    cout << S1.checkIfPermutation(s1, s2);
    // bool ans = S1.checkIfPermutation(s1, s2);
    // cout << ans << endl;

    // for (auto i : S1.CharCountOfString(s1))
    // {
    //     cout << i << "   ";
    // }
    // cout << endl;

    // S1.checkIfPermutation(s1, s2);

    return 0;
}