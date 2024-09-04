/*
understanding racursion with 1 step approach
*/

#include <iostream>
using namespace std;

void reachHome(int start, int destination)
{

    cout<< "Distance covered : " << start << endl;
    // base case
    if (start == destination)
    {
        cout << "The person has arrived." << endl;
        return;
    }

    // processing
    start++;

    // recursive relation
    reachHome(start, destination);
}

int main()
{
    int start = 0;
    int destination = 11;
    reachHome(start, destination);
    return 0;
}