class Solution {
public:
    bool isValid(vector<vector<int>>& grid,int row, int col, int n, int m, vector<vector<int>>& vis){
        if (row>=0 && row<n && col>=0 && col < m && grid[row][col] == 1 && vis[row][col]==0){
            vis[row][col] = 1;
            return true;
        }
        return false;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,0));
        
        queue<pair<int,int>> q;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        int dis = 1;
        while (!q.empty()){
            int size = q.size();
          
            for (int i=0; i<size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                int delrow[4] = {-1,0,1,0};
                int delcol[4] = {0,1,0,-1};
            
                for (int j=0; j<4; j++){
                    int nrow = delrow[j] + row;
                    int ncol = delcol[j] + col;

                    if (isValid(grid,nrow,ncol,n,m,vis)){
                        ans[nrow][ncol] = dis;
                        q.push({nrow,ncol});
                    }
                }
            }
            dis++;
        }

        return ans;
    }
};