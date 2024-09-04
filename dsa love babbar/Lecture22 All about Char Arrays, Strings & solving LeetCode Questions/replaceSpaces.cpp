/*
Coding Ninjas :-
https://www.codingninjas.com/studio/problems/replace-spaces_1172172
*/

#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string &str)
{ //-> time complexity and space complexity both O(n)
    string temp = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            temp += "@40";
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}

int main()
{
    string input;
    cout << "Enter your string : " << endl;
    getline(cin, input);
    input = replaceSpaces(input);
    cout << input << endl;
    return 0;
}