// /*
// practicing for est
// */

// #include<iostream>
// using namespace std;
// class A{
//     int a;
//     public:
//     A(){
//         cout<< "This is my default constructor for object A" << endl;

//     }
//     ~A(){
//         cout<< "This is the destructor for object A" << endl;
//         }
// };
// int main(){

// return 0;
// }

// If a object is created inside a block then destructor for that object is called at the end of the block
// we can access the private data members of a class using pulbic methods in that class
// 
// how the data members are inherited in different case
// remember 4 points
// 1. private members of the base class are never inherited and for others :-
// 2. public derivation mein jo data meber jaise tha vaisa hi rehta hai (muje koi problem nhi tum jaise the vaise raho)
// 3. protected derivation mein sare protected bante hain
// 4. private  derivation mein sarein private data members ban jate hain

// ambiguity resolution in C++
// suppose a class d1 derived from b1 and b2 and both the classes b1 and b2 have 
// a method called say() and we called say method for an object of derived class d1 then we have to resolve this ambiguity
// for ex we want to call say of class b2 
// then we will do this in the d1
// public:
// void say(){
//   b2::say();
// }
// when the base class and the derived class have the same name 
// then for an object of derived class the compiler will override the function of the base class and call the function of the derived class
//
                                        

// virtual base classes run for diamond problems 
// that means if a class is derived from two base classes having a variable with same name then virtual inheritance wil be worth using only when those two base classes are derived from the same base class

// we use initialisation list when we want our variables declared at the starting of the class
// 



// syntax to use new and delete keywords
// float* ptr= new float(8);
// delete ptr;
// and for declaring arrays dynamically we use
// int* ptr = new int[4];
// and to delete this array 
// delete[] ptr;

/*
using pointer to objects 
for example suppose their is a class Complex 
then 
Complex* cmpptr = new Complex;
and suppose it have methods setdata and getdata
cmpptr->setdata();
cmpptr->getdata();

similarly we can declare array of objects
Complex* ptr1 = Complex[4];
(ptr1+1)->setdata();
(ptr1+1)->getdata();
VIRTUAL functions are the example of run time polymorphism which is also called as late binding 
whereas function overloading and operator overloading are early binding or compile time polymorphism

****'this' keyword****
this keyword returns the pointer that points to current object

class A{
    int a;
    public:
    A& setData(int a){
        this-> a=a;
        return *(this);
    }
    void getData(){
        cout<<"The value of var1 is : " << endl;
    }
};

int main{   
    A a;
    (a.setData()).getData(); --> as a.setData() = a;
    return 0;
}*/


// #include<iostream>
// using namespace std;
// // now lets suppose there are two classes 
// class BaseClass{
//    public:
//    int var1_BaseClass;
//    virtual void display(){
//     cout<<"The value of var1_BaseClass is : " << var1_BaseClass << endl ;
//    }
// };
// class DerivedClass : public BaseClass{
//        public:
//    int var1_DerivedClass;
// void display();
// };
//    void DerivedClass::display(){
//     cout<<"The value of var1_DerivedClass is : " << var1_DerivedClass << endl ;
//     cout<<"The value of var1_BaseClass is : " << var1_BaseClass << endl ;
//    }

// int main(){
//     BaseClass* BaseClassPointer ;
//     DerivedClass DerivedClassObj;
//     BaseClassPointer = & DerivedClassObj;
//     DerivedClassObj.var1_BaseClass=1;
//     DerivedClassObj.var1_DerivedClass=2;
//     BaseClassPointer->display();
//     return 0;
// }




// practicing file input output
// #include <iostream>
// #include <fstream> // to access the classes having functions useful in operating file input and output 
// using namespace std;

// int main(){
    // ofstream --> out from the program
    // ifstream --> into the program
    // to write in a file first we have to open it 
    // there are two ways
    // 1. by using constructor
    // 2. by usign open() function

    // 1. By using constructor
    // out from the code
//     ofstream outfrom_code("yup.txt");
//     string st1,st2,st3;
//     st1="hello ji";
//     st2="namaste";
//     outfrom_code<<st1;
//     outfrom_code<<st2;
//     outfrom_code.close();

//     ifstream intocode("yup.txt");
//     getline(intocode, st2);
//     cout<< st2 << endl;


// string trial;
// cout<< "Enter the string : " << endl;
// getline(cin, trial);
// cout<< trial << endl;
//     return 0;
// }


// /*
// copy constructor 
// whenever we declare any required constructor we should also supply a defualt constructor so as to avoid errrors
// */

// #include<iostream>
// using namespace std;
// class A{
//     int var1;

//     public:
//     A(){}
//     A(A &obj){
// var1=obj.var1;
//     }
//     void setData(int var){
//         var1=var;
//     }
//     void getData(){
//         cout<< "The value of var1 is : " << var1 << endl;
//     }
// };
// int main(){
// A a1,a2(a1);
// a1.setData(7);
// // a2=a1;
// a2.getData();
// return 0;
// }

/*
dynamic initialisation of objects using constructor
*/

// #include<iostream>
// using namespace std;
// class A{
//     int var1;

//     public:
//     A(){}
//     A(int var){
//         var1=var;
//     }
//     void setData(int var){
//         var1=var;
//     }
//     void getData(){
//         cout<< "The value of var1 is : " << var1 << endl;
//     }
// };
// int main(){
// A a1(6);
// A a2=A(3);
// a1.getData();
// a2.getData();
// return 0;
// }
// ***********************************************************************************
/*
string manipulation in C++
*/

// #include<iostream>
// #include<cstring>
// using namespace std;

// int main(){
// // No.	String Function	Description
// // 1	strcat(str1, str2)	Concatenates str2 at the end of str1
// // 2	strcpy(str1, str2)	Copies str2 to str1
// // 3	strlen(str1)	Gives the length of str1
// // 4	strcmp(str1, str2)	Returns 0 if equal
// // 5	strchr(str, ch)	Returns pointer to first occurrence of ch in str
// // 6	strstr(str1, str2)	Returns pointer to first occurrence of str2 in str1
// // 7	strdup	Duplicates the string
// // 8	strlwr(str1)/strupr(str1)	Lower or upper case
// // 9	strev(str1)	Reverses the string
// int* ptr = new int[3];
// *ptr=1;
// *(ptr+1)=2;
// *(ptr+2)=3;
// cout<< *ptr << endl;
// return 0;
// }



/*
assignment 15 file input and output
sample60b.txt
*/

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main(){

char array1[1000];
char array2[1000];
cout<< "Enter the content for the file : " << endl;
cin.get(array1,1000);

    // using constructor to open the fil
// ofstream outfromcode("sample60b.txt");


// outfromcode<<array1;
// outfromcode.close();

// ifstream intothecode("sample60b.txt");
// intothecode.getline(array2,1000);
// cout<< array2 << endl;
// intothecode.close();

// using open function to open the files
ofstream outformcode;
outformcode.open("sample60b.txt");
outformcode<<array1;
outformcode<<"yo hi";
outformcode<<"namsjt";
outformcode.close();


ifstream intothecode;
intothecode.open("sample60b.txt");
// intothecode.getline(array1,1000);
// cout<< array1 << endl;
// intothecode.getline(array2,1000);
// cout<< array2 << endl;
for (; intothecode.eof()==0; )
{
    intothecode.getline(array1,1000);
    cout<< array1 << endl;
}

return 0;
}