/*
Lists in STL
*/

#include<iostream>
#include<list>
using namespace std;

void printList(list<int>& Mylist){
    for (int i : Mylist)
    {
            cout<< i << " " ;
    }
    cout << endl;
}

int main(){
    list<int> myList1;
    myList1.push_back(1);
    myList1.push_front(2);
    printList(myList1);

    myList1.erase(myList1.begin());
    cout<< "After erase()" << endl;
    printList(myList1);

    cout<< "Size of list = " << myList1.size() << endl;

    // copying list
    list<int> myList2(myList1);
    cout<< "elements in myList2 are : " << endl;
    printList(myList2);

    list<int> myList3(5, 1);
    cout<< "Elements in myList3 are : " << endl;
    printList(myList3);

return 0;
}