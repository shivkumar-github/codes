/*
member functions and template oveloading in C++
*/

#include <iostream>
using namespace std;

template <class T>
class Shivkumar
{
    T data1;

public:
    Shivkumar(T a)
    {
        data1 = a;
    }
    void display();
};

// display can also be declared as
template <class T>
void Shivkumar<T>::display()
{
    cout << "The value of data1 is : " << data1 << endl;
}

template <class T>
void func1(T a){
    cout<< "This is func1() and a = " << a << endl;
}

void func2(int a){
    cout<< "This is func2() and a = "<< a << endl;
}
int main()
{
    func1(2); // Exact match has the highest priority
    return 0;
}