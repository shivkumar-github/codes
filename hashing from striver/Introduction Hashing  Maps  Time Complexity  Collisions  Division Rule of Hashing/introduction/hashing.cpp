/*
Hasing is used to reduce time for execution in handling large datas by prestoring and fetching
for example - array 1 3 2 1 3
we need to tell how many time an element occures in the array
rather than calculating every time we will calculate it once and store it and whenever required we will fetch it again.
*/

#include <iostream>
#include <map>
#include <unordered_map>
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
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
                mpp[arr[i]]++;
        }

        // iterating through map
        // for (auto it : mpp)
        // {
        //         cout<< it.first << "->" << it.second << endl;
        // }
        

        int q;
        cin >> q;
        while (q--)
        {
                int number;
                cin >> number;
                // fething
                // cout << hash[number] << endl;
                cout<< mpp[number] << endl;
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