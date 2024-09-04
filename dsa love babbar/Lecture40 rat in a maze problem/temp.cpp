/*

*/

#include<iostream>
#include<vector>

using namespace std;
int main(){
        int n = 3;
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        cout << ans[i][j] << endl;
                }
                
        }
        
        return 0;
}