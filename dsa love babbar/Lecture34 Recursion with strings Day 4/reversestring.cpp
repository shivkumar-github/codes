/*
reversing the string using recursion
*/

#include <iostream>

using namespace std;

void reversingString(string &str, int s, int e)
{ // we have to pass the reference to the string
    // base case
    if (s >= e)
        return;

    // proccessing
    swap(str[s++], str[e--]);

    // recursion
    reversingString(str, s, e);
}

int main()
{
    string name = "abcd";
    reversingString(name, 0, name.size() - 1);

    cout << name << endl;
    return 0;
}