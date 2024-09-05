/*

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> vec(3,0);
	for (int i = 0; i < n;i++){
		int x, y, z;
		cin >> x >> y >> z;
		vec[0] += x;
		vec[1] += y;
		vec[2] += z;
	}
	cout << (!(vec[0] || vec[1] || vec[2]) ? "YES" : "NO");
	return 0;
}