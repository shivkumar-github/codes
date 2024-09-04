// Pointers to Derived Classes in C++
#include <iostream>
using namespace std;

class BaseClass{
public: 
int var1_BaseClass;
void display(){
    cout<< "The value of var1_BaseClass is : " << var1_BaseClass << endl;
}
};

class DerivedClass : public BaseClass{
public: 
int var1_DerivedClass;
void display(){
    cout<< "The value of var1_BaseClass is : " << var1_BaseClass << endl;
    cout<< "The value of var1_DerivedClass is : " << var1_DerivedClass << endl;
}
};

int main()
{
    BaseClass* BaseClass_pointer;
    BaseClass obj_BaseClass;
    DerivedClass obj_DerivedClass;
    BaseClass_pointer = &obj_DerivedClass; // Pointing BaseClass pointer to derived class object
    BaseClass_pointer->var1_BaseClass = 34;

    // BaseClass_pointer->var1_DerivedClass = 114; // will throw error as pointer of base class can not access variable in derived class
    BaseClass_pointer->display();
    
    DerivedClass* DerivedClass_pointer = &obj_DerivedClass;
    DerivedClass_pointer->var1_DerivedClass = 98;
    DerivedClass_pointer->var1_BaseClass = 18;
    DerivedClass_pointer->display();

    return 0;
}

/* while you cannot directly access members specific to the derived class using a pointer of the base class type, you can still achieve polymorphism and dynamic dispatch of functions declared in the base class through virtual functions.
 as in the previous tut we saw that we can not access variable of the derived class using pointer of the  base class
*/