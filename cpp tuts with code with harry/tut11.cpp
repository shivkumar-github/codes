// Break and Continue Statements in C++

#include <iostream>
using namespace std;

int main()
{
    // for (int i = 0; i < 40; i++)
    // {
    //     /* code */
    //     if(i==2){
    //         break; //used to exite from a loop or switch case statements
    //     }
    //     cout<<i<<endl;
    // }
    for (int i = 0; i < 40; i++)
    {
        /* code */
        if (i == 2)
        {
            continue; // skips the current condition
        }
        cout << i << endl;
    }

    return 0;
}
