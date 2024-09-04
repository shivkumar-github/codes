// Function Overloading with Examples in C++
/* Function overloading is a process to make more than one function with the same name
but different parameters, numbers, or sequence.*/

#include <iostream>
using namespace std;

// sum of two variables
int sum(int a, int b)
{
    return a + b;
}

// sum of three variables
int sum(int a, int c, int b)
{
    return a + b + c;
}

// Calculate the volume of a cylinder
int volume(double r, int h)
{
    return (3.14 * r * r * h);
}

// Calculate the volume of a cube
int volume(int a)
{
    return (a * a * a);
}

// Rectangular box
int volume(int l, int b, int h)
{
    return (l * b * h);
}

int main()
{
    // on the basis of no of arguments given compiler will decide which function to choose
    cout << "The sum of 3 and 6 is " << sum(3, 6) << endl;
    cout << "The sum of 3, 7 and 6 is " << sum(3, 7, 6) << endl;
    cout << "The volume of cuboid of 3, 7 and 6 is " << volume(3, 7, 6) << endl;
    cout << "The volume of cylinder of radius 3 and height 6 is " << volume(3, 6) << endl;
    cout << "The volume of cube of side 3 is " << volume(3) << endl;

}