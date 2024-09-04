/*
if give 234
output two three four
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string returnString(int digit)
{
    string rules[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    return rules[digit];
}

void sayDigits(int num, vector<string> &ans)
{
    // base case
    if (num == 0)
        return;

    // proccessing
    int digit = num % 10;
    string s = returnString(digit);
    ans.push_back(s);
    // recurance relation
    sayDigits(num / 10, ans);
}

int main()
{
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    vector<string> ans;
    sayDigits(num, ans);

    // printing in reverse order
    while (!ans.empty())
    {
        cout << ans.back() << " ";
        ans.pop_back();
    }
    cout << endl;
    return 0;
}