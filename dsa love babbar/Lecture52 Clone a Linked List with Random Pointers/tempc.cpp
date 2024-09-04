*

*/

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	unordered_map<int, int> mp;
	mp.insert({1, 2});
	// mp.erase(1);
	for (auto i : mp)
	{
		cout << i.first << i.second << endl;
	}
	

	return 0;
}