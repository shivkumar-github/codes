/*
Leet Code question
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s)
    {
        int i = 0;
        int n = s.size(); //--> why not working with size function- size function returns the size of array at runtime hence it will return new size every time
        while (i < n - 1)
        {
            if (s[i] == s[i + 1])
            {
                s.erase(i, 2);
                if (i != 0)
                    i--;
                n -= 2;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};

int main()
{
    string str1;
    cout << "Enter your string : ";
    getline(cin, str1);
    // str1.erase(2,2); ==> 2nd posion se do elements remove kardo
    // cout << "size of new str1 : " << str1.size() << endl; //==> checking if there is any erase function
    // cout << str1;

    Solution S1;
    cout << S1.removeDuplicates(str1) << endl;
    return 0;
}