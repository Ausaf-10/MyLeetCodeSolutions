class Solution {
public:
    int n,m;
    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1}};
    int DFS(int row, int col, vector<vector<int>>& grid){
        if (row < 0 || row>=n || col<0 || col>=m || grid[row][col] == 0) return 0;
        int originalValue = grid[row][col];
        grid[row][col] = 0;

        int maxi = 0;
        for (int i=0; i<4; i++){
            int nrow = row + directions[i][0];
            int ncol = col + directions[i][1];
            maxi = max(maxi, DFS(nrow, ncol, grid));
        }

        grid[row][col] = originalValue;
        return maxi + originalValue;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int maxi = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (!grid[i][j]) continue;
                maxi = max(maxi, DFS(i,j,grid));
            }
        }

        return maxi;
    }
};