// Single Inheritance deep dive : Examples + code 

#include <iostream>
using namespace std;

class Base
{
    int data1; // private by default and is not inheritable
public:
    int data2;
    int getdata1();
    int getdata2();
    void setdata();
};

int Base ::getdata1()
{
    return data1;
}
int Base ::getdata2()
{
    return data2;
}
void Base ::setdata()
{
    data1 = 10;
    data2 = 20;
}

class Derived : public Base // class is being derived publically
{
    int data3;

public:
    void process();
    void display();
};

void Derived ::process()
{
    data3 = data2 * getdata1(); // to acces private member of base class we have to acces through a method which is private that is why we used getdata1 instead of directly using data1
}
void Derived ::display()
{
    cout << "The value of data1 is : " << getdata1() << endl;
    cout << "The value of data2 is : " << data2 << endl;
    cout << "The value of data3 is : " << data3 << endl;
}
int main()
{
    Derived der;
    der.setdata();
    der.process(); 
    der.display();
    return 0;
}