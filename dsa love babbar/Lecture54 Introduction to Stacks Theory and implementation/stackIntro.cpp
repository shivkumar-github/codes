/*
Introduction to stack

    => stack is LIFO(last in first out) type of data structure
*/

#include <iostream>
#include <stack>
using namespace std;

// implementing stack using arrays
// every function has O(1) complexity
class Stack
{
public:
    // properties

    int size;
    int top; // to track index of stack
    int *array;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        array = new int[size]; // dynamically declaring size
        top = -1;
    }
    ~Stack()
    {
        delete array;
    }
    // push operation
    void push(int element)
    {
        // first check if space is available
        if (top >= (size - 1))
        {
            cout << "stack overflow! " << endl;
            return;
        }
        else
        {
            array[++top] = element;
        }
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack underflow! " << endl;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return array[top];
        }
        else
        {
            cout << "Stack is empty! " << endl;
            return -1;
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    // ** Using stack in STL

    // // creation of stack
    // stack<int> s;

    // // push operation
    // s.push(2);
    // s.push(3);

    // // pop
    // s.pop();

    // cout<< "Printing top element : " << s.top() << endl;

    // // empty
    // if(s.empty())
    //     cout<< "stack is empty " <<  endl;
    // else
    // cout<< "Stack is not empty " << endl;

    // // size of stack
    // cout<< "size of stack is : " << s.size() << endl;

    // ** Using user defined stack
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(44);
    st.push(44);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    st.pop();
    cout << st.peek() << endl;

    if (st.empty())
    {
        cout << "stack is empty !" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }

    return 0;
}