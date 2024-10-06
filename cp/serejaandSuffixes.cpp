#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int m, n;
//     cin >> n >> m;
//     vector<int> inp(n+1);
//     inp[0] = -1;
//     for(int i = 1;i<=n;i++){
//         cin >> inp[i];
//     }
//     vector<int> result(n+1);
//     result[0] = -1;
//     result[n] = 1;
//     vector<bool> ispresent(1e5, false);
//     ispresent[inp[n]] = true;
//     for(int i = n-1;i>=1;i--){
//         if(ispresent[inp[i]])
//             result[i] = result[i+1];
//         else{
//             result[i] = result[i+1] + 1;
//             ispresent[inp[i]] = true;
//         }
//     }
//     while(m--){
//         int index;
//         cin >> index;
//         cout << result[index] << endl;
//     }
// }

int main()
{
	int n, m;
	cin >> n >> m;
	int *arr = new int[n + 1];
	arr[0] = -1;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	set<int> st;
	for (int i = n; i >= 1; i--)
	{
		st.insert(arr[i]);
		arr[i] = st.size();
	}
	while (m--)
	{
		int ind;
		cin >> ind;
		cout << arr[ind] << endl;
	}
	return 0;
}