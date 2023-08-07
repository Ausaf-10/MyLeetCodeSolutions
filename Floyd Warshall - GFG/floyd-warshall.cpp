//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>& grid){
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    for (int i=0; i<n; i++){
	        for (int j=0; j<m; j++){
	            if (i == j) grid[i][j] = 0;
	            else if (i!=j && grid[i][j] == -1){
	                grid[i][j] = 1e8;
	            }
	        }
	    }
	    
	    for (int k = 0; k<n; k++){
	        for (int i=0; i<n; i++){
	            for (int j=0; j<m; j++){
	                if (grid[i][k]==1e8 || grid[k][j]==1e8) continue;
	                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
        	    }
        	}
	    }
	    
	    for (int i=0; i<n; i++){
	        for (int j=0; j<m; j++){
	            if (grid[i][j] == 1e8) grid[i][j] = -1;
	        }
	    }
	    
	    return ;
	}
	
};

//{ Driver Code Starts.
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
// } Driver Code Ends