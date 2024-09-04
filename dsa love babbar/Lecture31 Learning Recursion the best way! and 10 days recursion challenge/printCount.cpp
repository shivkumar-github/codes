/*
print counting
input = 5
output = 5 4 3 2 1
*/

#include <iostream>
using namespace std;

void printCount(int n)
{
    // base case
    if (n == 0)
        return;

    // recursion relation (RR) 
    // printCount(n - 1); // prints 1 2 3 4 5 6 7 8 9 ->> head recursion i.e. function is called recursively before any another operation

    // processing
    cout << n << " ";

    // recursion relation (RR)
    // printCount(n - 1); // prints 9 8 7 6 5 4 3 2 1  ->> tail recursion i.e. function is called after all processes and nothing is done after Recursive call   
}

int main()
{
    int input;
    cout<< "Enter the number : " << endl;
    cin >> input ;
    printCount(input);
    return 0;
}