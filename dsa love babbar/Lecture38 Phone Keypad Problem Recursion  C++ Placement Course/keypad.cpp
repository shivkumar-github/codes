/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
17. Letter Combinations of a Phone Number
Medium
Topics
Companies
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.




Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace 

class Solution
{
private:
    void solve(string digits, vector<string> &ans, int index, string forward, string *mapping)
    {
        // base case
        if (forward.size() >= digits.size())
        {
            ans.push_back(forward);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];

        for (int i = 0; i < value.length(); i++)
        {
            forward.push_back(value[i]);
            solve(digits, ans, index + 1, forward, mapping); // ek character ko dal ke uske possibilities ko store karva ke use bahar nikal do aur agle character pe chale jao
            forward.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() <= 0)
            return ans;

        string forward;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, index, forward, mapping);
        return ans;
    }
};

int main()
{
    string input = "23";
    // string input;
    cout << "Enter the digits." << endl;
    cin >> input;
    Solution s;
    vector<string> ans = s.letterCombinations(input);
    cout << "printing the answer" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}