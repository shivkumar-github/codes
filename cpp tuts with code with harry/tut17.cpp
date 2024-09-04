// Inline Functions, Default Arguments & Constant Arguments

#include <iostream>
using namespace std;

inline int product(int a, int b)
{
    // compiler inline function ko main mein rakh dega
    // we only give a hint to compiler to make a function inline, the final decision is taken by compiler depending upon various factors
    // It also can make a function inline by itself without any explicite instruction by programer
    // don't use inline in recursion and with static variable
    // make inline to only short functions(which have less operation), otherwise more memory will be required

    // static variable --> aisa variable jise function kabhi nahi bhulta
    //  static int c=0; // This executes only once
    //  c = c + 1; // Next time this function is run, the value of c will be retained c=(0,1,2,3,4,..)
    return a * b;
}

float moneyReceived(int currentMoney, float factor = 1.04)
{
    // write all default parameters on right side in a function
    return currentMoney * factor;
}

// int strlen(const char *p){//this is the example of constant argument

// }
int main()
{
    int a, b;
    // cout<<"Enter the value of a and b"<<endl;
    // cin>>a>>b;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    int money = 100000;
    cout << "If you have " << money << " Rs in your bank account, you will recive " << moneyReceived(money) << "Rs after 1 year" << endl;
    cout << "For VIP: If you have " << money << " Rs in your bank account, you will recive " << moneyReceived(money, 1.1) << " Rs after 1 year";
    return 0;
}
