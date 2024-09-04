/*
problem from geeks for geeks
https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1
*/

#include <iostream>
#include <string>
using namespace std;

// approach create an array temp of size 26(number of lowercase cahracters) where temp[0] represent number of occurances of 'a' temp[1] represents number of occurances of 'b  and so on
// given space complexity -> Expected Auxiliary Space: O(Number of distinct characters).
char returnMaxOccuringChar(string str)
{
    int array[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        int posOfChar = str[i] - 'a'; // index of the element which represents corresponding character
        array[posOfChar]++;
    }
    int indexOfMaxChar;
    int maxi = -1; // as possible min value of occurance will be 0 for any cahracter
    for (int i = 0; i < 26; i++)
    {
        if (maxi < array[i])
        {
            indexOfMaxChar = i;
            maxi = array[i];
        }
    }
    char finalAns = 'a' + indexOfMaxChar;
    return finalAns;
}