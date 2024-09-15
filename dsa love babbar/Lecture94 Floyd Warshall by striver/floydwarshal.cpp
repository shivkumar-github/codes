
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){ //initially we are given adjMatrix
	    int n = matrix.size();
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;// why 1e9 - because we want to find the minimum path hence for path doesn't exist we need a large value which when compared to any other shorter path will be replaced
	            }
	            // setting up diagonal element 0
	            if(i == j){
	                matrix[i][j] = 0;
	            }
	        }
	    }
	    
	    // calculating the distances
        for(int k = 0;k<n;k++){ // the outer loop will show via nodes
    	    for(int i = 0;i<n;i++){ // for each via node we will traverse over the whole matrix and see if we find the shorter distance between i and j nodes via k than the previously stored distance
    	        for(int j =0;j<n;j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<n;j++){
	            // setting back to -1
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}