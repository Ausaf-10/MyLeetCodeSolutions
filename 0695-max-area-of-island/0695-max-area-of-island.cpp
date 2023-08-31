class Solution {
public:
    int n,m;
    bool isValid(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &vis){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 1 && !vis[row][col]) return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &vis, int& area){
        vis[row][col] = 1; area = area + 1;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        for (int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            if (isValid(grid,nrow,ncol,vis)){
                dfs(grid,nrow,ncol,vis,area);
            } 
        }
        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));  
        
        int maxi = 0;

        for (int i=0; i<n; i++){                                           
            for (int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid,i,j,vis,area);
                    maxi = max(maxi,area);
                }
            }
        }
        return maxi;
    }
};