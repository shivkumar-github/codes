/*
Deque in STL
"dek"
*/

#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int>& Mydeque){
    for (int i : Mydeque)
    {
        cout<< i << " ";
    }
    cout << endl;
    
}

int main()
{
    deque<int> myDeque;

    // push_back() and push_front()
    myDeque.push_back(1); 
    myDeque.push_front(2);
    myDeque.push_front(3);
    // 3 2 1
    printDeque(myDeque);

    // pop_back()
    myDeque.pop_back();
    // 3 2 
    cout<< "myDeque after myDeque.pop_back() -> " << endl;
    printDeque(myDeque);

    // pop_front()
    myDeque.pop_front();
    // 2
    cout<< "myDeque after myDeque.pop_front() -> " << endl;
    printDeque(myDeque);

    cout<< "myDeque.at(0) = " << myDeque.at(0) << endl;

    // erase() => Time complexity O(n) => har element pe jake erase karna padta hai
    myDeque.push_front(1);
    // before erase()
    printDeque(myDeque);
    cout<< "Size before erase = " << myDeque.size() << endl;
    // after erase(myDeque.begin(), myDeque.begin() + 1)
    myDeque.erase(myDeque.begin(), myDeque.begin() + 1);
    cout<< "Size before erase = " << myDeque.size() << endl;

    cout<< "Elements remaning in myDeque are : " << endl;
    printDeque(myDeque);


    return 0;
}