// Static Data Members & Methods in C++

#include <iostream>
using namespace std;

// if we create a normal variable then each object will have its own count
// static variable is called as class variables as it is property of a class not the object
// it is only one and shared by all object // class us variable ko kabhi nahi bhulta

class Employee
{
    int id;
    static int count; // value of count can not be changed from here

public:
    void setData(void)
    {
        cout << "Enter the id of the employee : " << endl;
        cin >> id;
        count++;
    }

    void getData(void)
    {
        cout << "The id of employee is : " << id << " And the employee number is :" << count << endl;
    }

    // static member functions
    // this can access only static data members
    //  can be called independently of any object
    static void getcount(void)
    {
        // cout << id << endl; ---> will throw an error as static can not access not static data members
        cout << "The value of count is : " << count << endl;
    }
};

// following declaration states that count is static data member of class Employee
// which must be declared out of the class
int Employee ::count; // by default value is 0 and canbe chaneged only from here

int main()
{
    Employee harry, lovish, rohan;

    // harry.id = 1;
    // harry.count =1; //can not be done as these are private

    harry.setData();
    harry.getData();
    Employee ::getcount();

    lovish.setData();
    lovish.getData();
    Employee ::getcount();

    rohan.setData();
    rohan.getData();
    Employee ::getcount();
    return 0;
}