// Inheritance Synatx and Visibility Mode in C++

#include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee() {}
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
};

// Derived classs
// Creating a class derived from Employee Base Class
class Programmer : public Employee
{
public:
    int languagecode;
    Programmer() {}
    Programmer(int inpId)
    {
        languagecode = 9;
        id = inpId;
    }
    void getdata()
    {
        cout << "The salary of Employee is :" <<id << endl;
    }
};

int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << "The language code is :" << skillF.languagecode << endl;
    cout << "The id of employee is :" << skillF.id << endl;
    skillF.getdata();

    return 0;
}
/*

Notes:-
1. Default visibility Mode is private
2. Public Visibility Mode : Public members of a base class become public members of a base class
3. Private Visibility Mode : Public members of a base class become private members of a base class
4. Private members of a base class are never inherited

---> Derived Class
while writing a program double curly braces means us chij ko replace kiya jayega
class {{derived_class_name}} : {{visibility_mode}} {{base_class_name}}
{
    members/methods/etc..
}
*/