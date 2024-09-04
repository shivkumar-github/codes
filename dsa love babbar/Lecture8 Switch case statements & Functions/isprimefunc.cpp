/*
make function which checks if given number is a prime number or not
we can also write only return in case of void functions
for ex
void myfunct(){
    cout<<"This is my function. ";
    return;
}
*/

#include <iostream>
using namespace std;

bool isprime(int num)
{

    if (num <= 1)
    {
        return 1;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    if (isprime(num) == 1)
    {
        cout << "The number is a prime number. " << endl;
    }
    else if (isprime(num) == 0)
    {
        cout << "The number is not a prime number." << endl;
    }

    return 0;
}