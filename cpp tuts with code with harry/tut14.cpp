// Structers, Unions & Enums in C++

#include <iostream>
using namespace std;

// structures are used to store differnt data types
// In structures data is by default public hence it is less secure but can be made private explicitly
typedef struct employee
{
    // data
    int eID;
    char favchar;
    float salary;
} ep; // we need to give semicolon after defining a structure
//     because it is a user defined *data type* and

// jisko mein pehle struct employee bolta tha use aab ep bolunga
// as we know we have to put a semicolon when defination of a data type is complete
// also can be done by typedef struct employee ep
// When names of datatypes become difficult to use in programs, typedef is used with user-defined datatypes.
//---> general syntax is--> typedef existing_name alias_name;

union money
{
    // data
    int pounds;
    float rupees;
    char carchar;
    // if we want to use only one of pounds , rupees , carchar
    // memory is shared
};

int main()
{
    enum meal
    {
        breakfast,
        lunch,
        dinner
    };
    meal mfirst = breakfast;
    cout << "The condition (mfirst==0) is :" << (mfirst == 0) << endl;
    cout << "The value of mfirst is :" << mfirst << endl;
    cout << breakfast << endl;
    cout << lunch << endl;
    cout << dinner << endl; // assignes value to each according to numbering (0,1,2,3,..)

    struct employee shubham; // shubham ek employee hai
    ep harry;
    struct employee rohandas;

    harry.eID = 231080053;
    harry.favchar = 'k';
    harry.salary = 12000000;
    cout << "The value of harry.eID is :" << harry.eID << endl;
    cout << "The value of harry.favchar is :" << harry.favchar << endl;
    cout << "The value of harry.salary is :" << harry.salary << endl;

    union money m1;
    m1.pounds = 800;
    m1.rupees = 9;
    cout << m1.rupees << endl;
    cout << m1.pounds << endl;
    // only one value will be printed which is most recently entered

    return 0;
}

// enum ===> numbering karta hai
// union ==>when we want to use only one of them/ we can use only one of them