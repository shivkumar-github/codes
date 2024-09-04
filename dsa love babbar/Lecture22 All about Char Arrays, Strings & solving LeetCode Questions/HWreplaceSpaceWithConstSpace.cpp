/*
Coding Ninjas :-
https://www.codingninjas.com/studio/problems/replace-spaces_1172172
*/

#include <iostream>
#include <string>
using namespace std;

// string replaceSpaces(string &str)
// { //-> time complexity and space complexity both O(n)
//     int n = str.size();
//     for (int i = 0; i < n; i++)
//     {
//         if (str[i] == ' ')
//         {
//             str.push_back(' ');
//             str.push_back(' ');
//         }
//     }
//     char temp1, temp2;
//     char temptemp1;
//     char temptemp2;
//     for (int i = 0; i < str.size(); i++)
//     {

//         if (str[i] == ' ')
//         {
//             str[i] = '@';
//             temp1 = str[i + 1];
//             temp2 = str[i + 2];
//             str[i + 1] = '4';
//             str[i + 2] = '0';
//             for (int k = i + 2; k + 1 < str.size();)
//             {
//                 temptemp1 = temp1;
//                 temptemp2 = temp2;
//                 temp1 = str[k + 1];
//                 temp2 = str[k + 2];
//                 str[k + 1] = temptemp1;

//                 str[k + 2] = temptemp2;

//                 k += 2;
//             }
//         }
//     }

//     return str;
// }
string replaceSpaces(std::string &str)
{
    int spaceCount = 0;
    int n = str.size();

    // Count the number of spaces
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ' ')
        {
            spaceCount++;
        }
    }

    // Calculate the new length of the string after replacement
    int newLength = n + 2 * spaceCount; // seedhe nahi to ulta sahi
    str.resize(newLength);

    // Replace spaces with "%20" from the end of the string
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[--newLength] = '0';
            str[--newLength] = '2';
            str[--newLength] = '%';
        }
        else
        {
            str[--newLength] = str[i];
        }
    }

    return str;
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