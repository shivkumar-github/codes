#include <bits/stdc++.h>
using namespace std;
# define lli long long int
 
int main() {
    
    lli n,m,a;
    cin >> n >> m >> a;
    n = n/a + (n%a != 0); // ceil value
    m = m/a + (m%a != 0); // ceil value
    cout << m*n << endl;
    return 0;
}