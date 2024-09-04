/*

*/

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	unordered_map<int, bool> mp;
	// cout << mp[3];
	// for (auto i : mp)
	// {
	// 	cout << i.first  << " " << i.second  << " " << endl;
	// }
	// cout << mp.at(3);
	if(mp[3]==0)
		cout << mp[3];

	return 0;
}