/*
List in C++ STL

    => Access is fast in arrays
    but for deletion and insertion is fast in list

*/

#include <iostream>
#include <list>
using namespace std;

// A function to display the list
// template <class T>
void display(list<int> &lst)
{
    typename list<int>::iterator it; // as the type T is not defined we have to write a keyword typename to tell the compiler
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << endl;
}

int main()
{

    // why to use list
    // for ex consider an array
    // 6 7 8 9 and we want to delete 7 then have to move every element after 7 to the precceding position
    // 6 8 9
    list<int> list1; // List of 0 length
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_back(12);
    display(list1);


    // Removing elements from list

    // list1.pop_back();
    // cout<< "The list after using of pop.back()" << endl;
    // display(list1);
    // cout<< "The list after using of popfront()" << endl;
    // list1.pop_front();
    // display(list1);

    // list1.remove(9); // 9 ke sare occurances delete ho jayenge
    // display(list1);

    list1.sort(); // most common sorting is 
    display(list1);  


    // operations on list2
    list<int> list2(3); // Empty list of size 3
    // ** do we have to declare the size of list while assigning the values directly using the iterators
    list<int> :: iterator iter;
    iter = list2.begin();
    *iter =  45;
    iter++;
    *iter = 6;
    iter++;
    *iter = 9;
    iter++;
    cout<< "The list2 is : " << endl;
    display(list2);

    // merging two lists
    list1.merge(list2);
    cout<< "list1 after merging is : " << endl;
    display(list1);

    // reversing the list
    list1.reverse();
    cout<< "list1 after reversing is : " << endl;
    display(list1);

    // to check whether the list is empty or not
    cout << " list1.empty() = " << list1.empty() << endl;


    return 0;
}