// Virtual Functions in C++

#include<iostream>
using namespace std;

class BaseClass{
    public: 
    int var1_BaseClass = 1;
    virtual void display(){ // Agar mere class ka pointer derived class ke object ko point karein to uska display run karna
    cout<< "The value of var1_BaseClass is : " << var1_BaseClass << endl;
    }
};

class DerivedClass : public BaseClass{
    public: 
    int var1_DerivedClass = 2;
    void display(){
    cout<< "The value of var1_BaseClass is : " << var1_BaseClass << endl;
    cout<< "The value of var1_DerivedClass is : " << var1_DerivedClass << endl;
    }
};

int main(){
    BaseClass* BaseClass_pointer;
    BaseClass obj_BaseClass;
    DerivedClass obj_DerivedClass;

    BaseClass_pointer = &obj_DerivedClass;
    BaseClass_pointer -> display();

return 0;
}

/*
*******for more understanding refer the paragraph provided by chatgpt***

Virtual Functions in C++
Pointer of Base Class Type:

A pointer of the base class type (BaseClass*) can point to objects of both the base and derived classes.
Accessing Members:

A pointer of the base class type can access members and functions declared in the base class.
It cannot directly access members specific to the derived class unless a common virtual function is declared in the base class.
Polymorphism with Virtual Functions:

Virtual functions allow dynamic dispatch, meaning the actual function executed is determined by the type of the object at runtime.
If a virtual function is declared in the base class and overridden in the derived class, calling it through a pointer of the base class type will execute the derived class's version.
Without Virtual Functions in Base Class:

Without virtual functions in the base class, function calls through a base class pointer are statically bound to the base class's version.
Introducing new functions in the derived class might lead to mismatches and errors when using a pointer of the base class type.

*/