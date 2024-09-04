// More on friend functions

#include <iostream>
using namespace std;
class c1;
class c2;
void exchange(c1 &x, c2 &y);
class c1
{
    int val1;

public:
    void indata(int a)
    {
        val1 = a;
    }
    void display(void)
    {
        cout << val1 << endl;
    }
    friend void exchange(c1 &x, c2 &y); // you can declare friend function in private or in public
};

class c2
{
    int val2;

public:
    void indata(int b)
    {
        val2 = b;
    }
    void display(void)
    {
        cout << val2 << endl;
    }
    friend void exchange(c1 &x, c2 &y);
};

// declaring a function which swaps the data of both the classes c1 and c2
void exchange(c1 &x, c2 &y) // reference to a data of type c1 and data of type c2 //reference variable // must be used to actually change the value
{
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}
int main()
{
    c1 oc1;
    c2 oc2;
    oc1.indata(34);
    oc2.indata(67);

    exchange(oc1, oc2);

    oc1.display();
    oc2.display();

    return 0;
}