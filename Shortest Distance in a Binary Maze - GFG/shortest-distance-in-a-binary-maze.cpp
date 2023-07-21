//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(vector<vector<int>> &grid, int row, int col, int n, int m){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 1) return true;
        return false;
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> distance(n,vector<int> (m,1e9));
        distance[source.first][source.second]=0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        
        while (!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            if (row == destination.first && col == destination.second) return dis;
            
            q.pop();
            
            // CHECK FOR ITS NEIGHBORS
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            for (int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (isValid(grid,nrow,ncol,n,m)){
                    if (distance[nrow][ncol] > dis + 1){
                        distance[nrow][ncol] = dis + 1;
                        q.push({dis+1,{nrow,ncol}});
                    }
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends