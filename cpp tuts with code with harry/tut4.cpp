// variable scope and data types

#include <iostream>

using namespace std;
int glo = 6;
// this is a global variable
void sum()
{
    int a;
    cout << glo;
    /* there is no variable named glo(i.e. no local variable) in function sum hence
     it will search for a global variable */
}

int main()
{
    int glo = 9;
    glo = 78;
    int a = 14, b = 15;
    float pi = 3.14;
    char c = 'd';
    bool is_true = false;
    sum();
    cout << glo << is_true;
    /* here in main function variable named glo
     is present (which is local variable) hence
     priority given to local variable and value of local variable will be printed */
    //  char a = 'a';
    //  cout << a << endl; we can not give same name to two variables though they are of different types
    return 0;//anything written after return 0 is not executed
}