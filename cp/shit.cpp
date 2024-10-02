#include<bits/stdc++.h>
using namespace std;
int main(){
	int tolwr = 'a' - 'A';
	string s, s1;
	cin >> s;

	for (int i = 0; i < s.size();i++){
		char c = s[i];
		if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'Y' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c!='y'){
			cout << '.';
			if(c >= 'A' && c <= 'Z') cout << char(c + tolwr);
			else cout << c;
		}
	}
	return 0;
}