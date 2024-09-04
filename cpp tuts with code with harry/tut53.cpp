// this pointer in C++
#include <iostream>
using namespace std;

class A
{
    int a;

public:
    A &setData(int a) // might be a little bit confusing
    {
        this->a = a;
        return *(this);
    }

    void getData(void)
    {
        cout << "The value of a is : " << a << endl;
    }
};
int main()
{
    // 'this' is a keyword which is a pointer which points to the object which has called the member functions
    A a;
    a.setData(4).getData(); // this is equivalent to (a.setData(4)).getData()
    // ((a.setData(4)).setData(90)).getData(); // in this we can continue looping and the a will get the recently assigned value
    // a.getData();
    return 0;
}