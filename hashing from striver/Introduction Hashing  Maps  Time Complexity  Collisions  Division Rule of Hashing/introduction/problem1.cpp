/*
Hasing is used to reduce time for execution in handling large datas by prestoring and fetching
for example - array 1 3 2 1 3
we need to tell how many time an element occures in the array
rather than calculating every time we will calculate it once and store it and whenever required we will fetch it again.
*/

#include <iostream>
using namespace std;
int main()
{
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
                cin >> arr[i];
        }

        // precompute
        int hash[13] = {0};
        for (int i = 0; i < n; i++)
        {
                hash[arr[i]]++;
        }

        int q;
        cin >> q;
        while (q--)
        {
                int number;
                cin >> number;
                // fething
                cout<< hash[number] << endl;
        }
        /*
5
1 3 2 1 3
5
1
4
2
3
12
        
        */


        return 0;
}