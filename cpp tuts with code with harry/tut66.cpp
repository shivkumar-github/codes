/*
class templates with default parametres
*/

#include <iostream>
using namespace std;

template <class T1 = int, class T2 = float, class T3 = char>
class Shivkumar
{
    T1 data1;
    T2 data2;
    T3 data3;

public:
    Shivkumar(T1 a, T2 b, T3 c)
    {
        data1 = a;
        data2 = b;
        data3 = c;
    }
    void display()
    {
        cout << "data1 = " << data1 << endl;
        cout << "data2 = " << data2 << endl;
        cout << "data3 = " << data3 << endl << endl;
    }
};
int main()
{

    Shivkumar<> obj1(2, 2, 'c');
    obj1.display();

    Shivkumar<int,char,char> obj2(1,'a', 'b');
    obj2.display();
    return 0;
}