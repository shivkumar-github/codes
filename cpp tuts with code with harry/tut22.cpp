// OOPs Recap & Nesting of Member Functions in C++

// OOPs - Classes and objects

// C++ --> initially called --> C with classes by stroustroup
// class --> extension of structures (in C)
// structures had limitations
//      - members are public
//      - No methods
// classes --> structures + more
// classes --> can have methods and properties
// classes --> can make few members as private & few as public
// structures in C++ are typedefed

// you can declare objects along with the class declarion like this:
/* class Employee{
            // Class definition
        } harry, rohan, lovish; */
// harry.salary = 8 makes no sense if salary is

#include <iostream>
#include <string>
using namespace std;

class binary
{
public:
    void read(void);
    void ones_complement(void);
    void display(void);

private:
    string s;
    void check_binary(void);
};

// Nesting of member functions (insering one thing into another):
void binary ::read(void)
{
    cout << "Enter the string :" << endl;
    cin >> s;
    check_binary();
}

void binary ::check_binary(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "The entered number is not binary." << endl;
            exit(0); // exit (0) ; is used when we want to exit the program
            // the null character is not counted 
        }
        else
        {
            cout << "The number is binary." << endl;
            break;
        }
    }
}

void binary::ones_complement(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else if (s.at(i) == '1')
        {
            s.at(i) = '0';
        }
    }
}

void binary::display(void)
{
    cout << "Your binary number is:" << s << endl;
}

int main()
{

    binary b;
    b.read();
    b.display();
    // b.check_binary();
    b.ones_complement();
    b.display();

    return 0;
}
