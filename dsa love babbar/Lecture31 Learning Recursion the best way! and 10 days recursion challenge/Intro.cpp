/*
Recursion : when a function calls itself directly or inderectly then it is called recursion  ->> Aam zindagi
agar kisi badi ya complex problem ka solN depends on a small problem of same type then we use recursion to solve that bigger problem
(we just have to take first step and other steps will be completed automatically) untill the base case which we have entered
for example for finding 2^n
2^n = 2 * 2^(n-1)
f(n) = 2 * f(n-1)

1. we need a base case which will decide where to stop
2. and a recursion relation
3. processing in each recursion

The images of recursion tree and stack operations performed during recursion in factorial are added in the folder

 head recursion and tail recursion
 see the difference on geeks for geeks
*/

#include <iostream>
using namespace std;
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1); // factorial n - 1 ->> smaller problem and n factorial bigger problem
}
// int main()
// {
//     int n = 0;
//     int ans = factorial(n);
//     cout << ans << endl;
//     return 0;
// }