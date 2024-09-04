/*
stacks in STL
lifo => last in first out
*/

#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> myStack;
    
    myStack.push("1st inserted");
    myStack.push("2nd inserted");
    myStack.push("3rd inserted");

    cout<< "Top element -> myStack.top() -> " << myStack.top() << endl;
    myStack.pop();
    cout<< "After pop()" << endl;
    cout<< "Top element -> myStack.top() -> " << myStack.top() << endl;

    cout<< "myStack.size() = " << myStack.size() << endl;
    cout<< "myStack.empty() = " << myStack.empty() << endl;
return 0;
}