/*

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	queue<int> q;
	q.push(8);
	q.push(7);
	q.push(10);
	cout << q.size() << endl;
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}