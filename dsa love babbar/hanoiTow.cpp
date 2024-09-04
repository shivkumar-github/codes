/*
write a programme which gives steps for moving disks from rod A to rod C where third rod is B
*/
#include <iostream>
using namespace std;

void giveSteps(int n, char fromRod, char toRod, char auxRod)
{
    if (n <= 0)
        return;

    giveSteps(n - 1, fromRod, auxRod, toRod);
    cout << "move the disk numbered " << n << " from rod " << fromRod << " to the rod " << toRod << endl;
    giveSteps(n - 1, auxRod, toRod, fromRod);
}

int main()
{
    int n;
    cin >> n;
    giveSteps(n, 'A', 'C', 'B');
    return 0;
}