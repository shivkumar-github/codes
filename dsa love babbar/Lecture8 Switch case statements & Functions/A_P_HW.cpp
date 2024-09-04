/*
returning nth term of an A.P.
*/

#include <iostream>
using namespace std;

int returntheterm(int n)
{
    return (n * 3 + 7);
}
int main()
{
    int n;
    cout << "Which term do you want to find : " << endl;
    cin >> n;
    cout << "The " << n << " th term of this A.P. is : " << returntheterm(n) << endl;

    return 0;
}