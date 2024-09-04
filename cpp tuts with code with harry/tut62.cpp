/*
File I/O in C++ : open() and eof() functions in C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream out;

    // opening using member functions
    out.open("sample60.txt");
    out << "Hi"<<endl;
    out << "this is assignement 15.";
    // c type string should be used for taking content from the user as string can not a
    out.close();

    ifstream in;
    in.open("sample60.txt");
    string st1, st2;
    // in>>st1>>st2;
    // cout<< st1 << st2 << endl;

    while (in.eof()==0) // in.eof() returns non zero value when file ends
    {
        getline(in, st1);
        cout<< st1 << endl;
    }
    in.close();

    return 0;
}
