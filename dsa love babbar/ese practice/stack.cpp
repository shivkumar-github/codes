#include <iostream>
using namespace std;

class stack
{
        int top;
        int size;
        int *arr;

public:
        stack(int size)
        {
                top = -1;
                this->size = size;
                arr = new int[this->size];
        }
        ~stack(){
                delete arr;
        }
        void push(int element)
        {
                if (top >= size - 1)
                {
                        cout << "stack overflow!" << endl;
                        return;
                }
                arr[++top] = element;
        }
        int pop()
        {
                if (top <= -1)
                {
                        cout << "stack underflow!" << endl;
                        return -1;
                }
                else
                        return arr[top--];
        }
        int peek()
        {
                if (top <= -1)
                {
                        cout << "stack underflow!" << endl;
                        return -1;
                }
                else
                        return arr[top];
        }

        bool isEmp()
        {
                return (top <= -1);
        }
};

int main()
{
        stack s(4);
        s.push(45);
        s.push(21);
        s.push(33);
        s.push(31);
        s.push(345);

        cout << s.isEmp() << endl;
        cout << s.peek() << endl << endl;

      cout<< s.pop() << endl;
      cout<< s.pop() << endl;
      cout<< s.pop() << endl;
      cout<< s.pop() << endl;
      cout<< s.pop() << endl;
      
        cout << s.isEmp() << endl;

        return 0;
}