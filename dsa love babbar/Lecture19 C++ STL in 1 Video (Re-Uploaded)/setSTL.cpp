/*
set:-
Set Properties
C++ set has the following properties.

1. Unique Elements
No two elements in a set can be equal.

2. Immutable
We can add or remove elements from a set but we can't change the values of existing elements.

3. Sorted Order
Elements in a set are sorted following a specific strict weak ordering.
By default, C++ sets are sorted in ascending order but we have the option to change that.

4. Associative
Elements of a set are referenced using their key, not by their position in the container.
This is unlike arrays where elements are accessed using indexes.


*/

#include <iostream>
#include <set>
using namespace std;

void printmySet(set<int> &mySet)
{
    for (auto i : mySet)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    set<int> mySet1;

    mySet1.insert(5);
    mySet1.insert(5);
    mySet1.insert(5);
    mySet1.insert(1);
    mySet1.insert(6);
    mySet1.insert(6);
    mySet1.insert(0);
    mySet1.insert(0);
    mySet1.insert(0);
    printmySet(mySet1);
    
    // erase function
    // mySet1.erase(mySet1.begin());
    // printmySet(mySet1);

    // cout << "5 is present or not -> " << mySet1.count(5) << endl;
    // cout << "-5 is present or not -> " << mySet1.count(-5) << endl;

    set<int>::iterator itr = mySet1.find(5);
    

    for (int i = 0; i < mySet1.size(); i++)
    {
        
        cout<< *() << endl;
    }
    
    // *itr = 7; // value of an element present in set can not be modified

    // // printing elements using iterator
    // for (auto it = itr; it != mySet1.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    // cout << endl;

    return 0;
}