// Copy Constructor

#include <iostream>
using namespace std;

class Number
{
    int a;

public:
    Number()
    {
        a = 0;
    };
    Number(int num)
    {
        a = num;
    }

    // when no copy constructor is found then compiler supplies its own copy constructor
    Number(Number &obj)
    {
        cout << "The copy constructor is called !!" << endl;
        a = obj.a;
    }

    void display()
    {
        cout << "The number for this object is :" << a << endl;
    }
};

int main()
{
    Number x, y, z(45), z2;
    x.display();
    y.display();
    z.display();

    // z1 should exactly resemble to z
    Number z1(z);
    z1.display();

    z2 = z; 
    // Copy construstructor is not invoked as the we have copied using assginement operator '=' 
    // and not the copy constructor 
    z2.display(); 

    Number z3 = z; 
    // Copy constructor is invoked  as in same line object created and assigned  (It is the rule of language)
    z3.display();

    return 0;
}