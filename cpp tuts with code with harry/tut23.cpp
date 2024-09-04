// C++ Objects Memory Allocation & using Arrays

// The memory is allocated to the variables of the class only the object is declared.
// not allocated when class is declared
// every object has an individual copy of all the variables of the class

// but the memory allocated to objects only when class is declared.
//  only one copy of functions is shared among each object.

#include <iostream>
using namespace std;

class shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;
    // don't give access of variables to users hence they are private

public:
    void initCounter(void) { counter = 0; }
    void setPrice(void);
    void displayPrice(void);
};

void shop::setPrice(void)
{
    cout << "Enter Id of your item no " << counter + 1 << endl; // as counting in array from 0 but in real world we need initiation from 1
    cin >> itemId[counter];
    cout << "Enter the price of yout item :" << endl;
    cin >> itemPrice[counter];
    counter++;
}

void shop::displayPrice(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "The price of item with Id " << itemId[i] << " is " << itemPrice[i] << endl;
    }
}
// this program can be done better by using string instead of int array as by using string along with #include <string>
//  which will reduce the code used for taking input and output
int main()
{

    shop dukan;
    dukan.initCounter();
    dukan.setPrice();
    dukan.setPrice();
    dukan.setPrice();
    dukan.setPrice();
    dukan.displayPrice();

    return 0;
}
// we can also create n number of object using arrays for a class
//  for ex suppose we want to declare 10 object students in class student
//  student stud[10];
// this will create 10 student objects