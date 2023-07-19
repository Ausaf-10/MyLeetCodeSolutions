//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(vector<vector<int>>& grid,int row, int col, int n, int m, vector<vector<int>>& vis){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 1 && !vis[row][col]){
            vis[row][col] = 1;
            return true;
        }
        return false;
    }
    void bfs(vector<vector<int>>& grid,int row, int col, vector<vector<int>>& vis, vector<pair<int,int>>& vec){
        int n = grid.size();
        int m = grid[0].size();
        
        
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        
        int row0 = row;
        int col0 = col;
        vec.push_back({row-row0,col-col0});
        
        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            
            for (int i=0; i<4; i++){
                int nrow = delrow[i] + row; 
                int ncol = delcol[i] + col; 
                if (isValid(grid,nrow,ncol,n,m,vis)){
                    q.push({nrow,ncol});
                    vec.push_back({nrow-row0,ncol-col0});
                }
            }
        }
        
        return ;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        set<vector<pair<int,int>>> st;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int,int>> vec;
                    bfs(grid,i,j,vis,vec);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends