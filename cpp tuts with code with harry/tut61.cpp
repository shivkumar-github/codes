/*
File I/O in C++ : Read/Write in the same program & closing files
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    // connecting our file with hout stream
    ofstream hout("sample60b.txt"); // out from the program to file

    // creating a name string and filling it with the string entered by the user
    string name;
    cout << "Enter your name : " << endl;
    cin >> name;

    // writing a string to the file
    hout << name + " is my name. ";
    hout.close();

    ifstream hin("sample60b.txt");
    string content;
    getline(hin, content);
    cout << "the content of this file is :" << content << endl;
    hin.close();
    return 0;
}