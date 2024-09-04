/*
vectors in STL

*/

#include <iostream>
#include <vector>
using namespace std;

void printMyvec(vector<int> &myVec)
{
    for (int i : myVec)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> myVec1;

    // => push_back() and increament in capacity of vector
    // when vector is full and we try to push element in it then its capacity *doubles*
    // (purana vectors se double size ka naya vector banta hai aur purana discard ho jata hai)
    cout << endl
         << "capacity = " << myVec1.capacity() << endl;
    myVec1.push_back(1);
    cout << "now capacity = " << myVec1.capacity() << endl;

    myVec1.push_back(2);
    cout << "now capacity = " << myVec1.capacity() << endl;

    myVec1.push_back(3);
    cout << "now capacity = " << myVec1.capacity() << endl;
    cout << "But the size of the vector = " << myVec1.size() << endl
         << endl; // size() => kitne elements pade hue hai

    // at() function
    cout << "Element at index 2 = " << myVec1.at(2) << endl;

    // front() and back() functions
    cout << "myVec1.front() = " << myVec1.front() << endl; // first element of vector

    cout << "myVec1.back() = " << myVec1.back() << endl; // last element of vector

    // pop_back() function

    myVec1.pop_back();
    cout<< "vector after first pop_back() : " << endl;
    printMyvec(myVec1);
    myVec1.pop_back();
    myVec1.pop_back();

    // capacity after pop back => remains same
    cout << "capacity after popback is -> " << myVec1.capacity() << endl;

    myVec1.push_back(1);
    myVec1.push_back(2);
    myVec1.push_back(3);

    // clear() function
    cout << "Before clear size is : " << myVec1.size() << endl;
    myVec1.clear();
    cout << "After clear size is : " << myVec1.size() << endl;
    cout << "After clear capacity is : " << myVec1.capacity() << endl;

    // creating vector of predefined size
    vector<int> myVec2(5, 1); // 5 size ka vector banao aur saare elements ki value 1 set kar do
    cout << "Elements of myVec2 are : " << endl;

    /* The range-based for loop in C++ provides a concise way to iterate over the elements of a container,
    such as an array, vector, or other iterable data structure.
    The syntax is as follows:
    for (element_declaration : range)
    {
        // loop body
    }

    */

    for (int i : myVec2)
    {
        cout << i << " ";
    }
    cout << endl;

    // It also has copy constructor
    vector<int> myVec3(myVec2);
    cout << "Elements of myVec3 are : " << endl;
    for (int i : myVec3)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}