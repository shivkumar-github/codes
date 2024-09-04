// Friend Functions in C++

#include <iostream>
using namespace std;

class Complex
{
    int realp, imgp;

public:
    friend Complex sumComplex(Complex o1, Complex o2); // This line means that
    // a non-member sumComplex function is allowed to manipulate the data members within the class
    // you can declare friend function in private or in public

    void setNumber(int realp1, int imgp1)
    {
        imgp = imgp1;
        realp = realp1;
    }
    void printNumber(void)
    {
        cout << "Your number is : " << realp << " + " << imgp << "i" << endl;
    }
};

Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setNumber((o1.realp + o2.realp), (o1.imgp + o2.imgp));
    return o3;
}

int main()
{
    Complex c1, c2, sum;

    c1.setNumber(1, 4);
    c2.setNumber(5, 8);

    sum = sumComplex(c1, c2);
    sum.printNumber();

    return 0;
}

/*  Properties of friend functions :-
1.Not in the scope of class
2. Since it is not in the scope of the class,
 it can not be called from the object of that class. c1.sumComplex() == invalid
3.Can be invoked/called without the help of any object
4.Usually contains objects as arguements as,
 usually we give objects as arguments to access the private data
5. Can be declared inside public or private section of the class as it is just 'access warrent'.
6.It can not access directly members directly by their names and need object_name.member_name to access any member.
*/