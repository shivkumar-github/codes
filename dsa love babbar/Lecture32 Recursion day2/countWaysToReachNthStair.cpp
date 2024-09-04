/*
coding ninjas:- (link is provided please add it)
count ways to reach n th stairs where a person can take either 1 or 2 steps at a time
*/

#include <iostream>
using namespace std;

int ways(int stairs)
{
    if (stairs < 0)
    {
        return 0;
    }
    if (stairs == 0) // 0 th stairs se 0 th stair pe jane ka ek hi way hai
    {
        return 1;
    }

/*
considering a single final case (as property of recursion we solve 1 problem and the rest is solved automatically) 
->>selecting final case because the execution of function starts from last 
->> their are two possible ways in which we will  reach n th stair (as person can always take two or one step)
    1. either by taking a single step(from n -1 to n th)
    2. or by taking single step (from n - 2 to n th)

therefore total possible ways = ways to reach n-1 th stair + ways to reach n - 2 th stair
    ->> f(n) = f(n-1) + f(n-2); ->> recursive relation

    ->> how to approach the problem
    think how we can complete the last step 
    and the rest steps will be automatically taken (hint which tells us that recursion will be applied here)
    and the base cases

*/
    int ans = ways(stairs - 1) + ways(stairs - 2);
    return ans;
}

int main()
{
    int stairs;
    cout<< "Enter the number of stairs" << endl;
    cin >> stairs ;
    cout<< "The number of ways to reach nth stair are : " << ways(stairs) << endl;
    return 0;
}