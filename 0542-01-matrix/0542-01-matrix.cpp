class Solution {
public:
    int n,m;
    bool isValid(vector<vector<int>>& grid,int row, int col, vector<vector<int>>& vis){
        if (row>=0 && row<n && col>=0 && col < m && grid[row][col] == 1 && vis[row][col]==0){
            vis[row][col] = 1;
            return true;
        }
        return false;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));
        
        queue<pair<int,pair<int,int>>> q;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 0){
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()){
            auto node = q.front(); q.pop();

            int dis = node.first, row = node.second.first, col = node.second.second;
            
            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
        
            for (int i=0; i<4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if (isValid(grid,nrow,ncol,vis)){
                    ans[nrow][ncol] = dis + 1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }
          
        }

        return ans;
    }
};