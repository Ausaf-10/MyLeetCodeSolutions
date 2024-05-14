class Solution {
public:
    int n,m;
    bool isValid(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid){
        if (row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col])  return true;
        return false;
    }
    void fun(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int &maxi, int& sum){
        sum+=grid[row][col];
        vis[row][col] = 1;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};
        for (int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if (isValid(nrow, ncol, vis, grid)){
                fun(nrow, ncol, grid, vis, maxi, sum);
            }
        }
        maxi = max(maxi, sum);
        sum-=grid[row][col];
        vis[row][col] = 0;
        return ;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        int maxi = -1;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                vector<vector<int>> vis(n, vector<int>(m,0));
                if (grid[i][j] == 0) continue;
                int sum = 0;
                fun(i, j, grid, vis, maxi, sum);
            }
        }
        return maxi == -1 ? 0 : maxi;
    }
};