/*
Accepts a nubmer
Return the difference between product of its digits and sum of its digits
*/

#include <iostream>
using namespace std;

void givediff(int n)
{
    int sum = 0, prod = 1;

    // logic
    for (; n > 0;)
    {
        sum += (n % 10);
        prod *= (n % 10);
        n /= 10;
    }

    // if else condition to give only positive value
    if (prod - sum)
    {
        cout << "The difference between sum and product of digits of that number is : " << int(prod - sum) << endl;
    }
    else
    {
        cout << "The difference between sum and product of digits of that number is : " << int(sum - prod) << endl;
    }
}

int main()
{
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;
    givediff(num);
    return 0;
}