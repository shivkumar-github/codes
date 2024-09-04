/*
File I/O in C++ : Reading and writing Files in C++
*/
/*
The useful classes for working with files in C++ are:
1. fstream
2. ifstream ---> derived from fstream base
3. ofstream ---> derived from fstream base
*/

/*In order to work with files in C++, you will have to open it. Primarly there are two ways to open a file:
1. Using the constructor
2. Using the member function open() of the class
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string st1 = "harry bhai";
    string st2, st3;
    // // opening file using constructor and writing it // of --> out from the program
    // ofstream out("sample60b.txt"); //write operation
    // out<<st1;

    // Opening files using consructor and reading from it // if --> in to the program
    ifstream in("sample60b.txt"); // reading operation
    // in>>st2;
    getline(in, st1);
    getline(in, st2);
    getline(in, st3);
    cout << st1 << st2 << endl
         << st3 << endl;
    in.close();
    return 0;
}