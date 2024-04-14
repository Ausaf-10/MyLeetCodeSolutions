class Solution {
public:
    int n,m;
    bool isValid(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        if (row>=0 && row<n && col>=0 && col<m && !vis[row][col]){
            vis[row][col] = 1;
            return true;
        }
        return false;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        int cnt0 = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j]){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
                else cnt0++;
            }
        }

        if (cnt0 == 0) return -1;

        int time = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                int row = q.front().first, col = q.front().second;
                q.pop();

                int delrow[4] = {-1, 0, 1, 0};
                int delcol[4] = {0, 1, 0, -1};
                for (int i=0; i<4; i++){
                    int nrow = delrow[i] + row;
                    int ncol = delcol[i] + col;
                    if (isValid(nrow, ncol, grid, vis)){
                        q.push({nrow, ncol});
                    }
                }

            }
            time++;
        }
        return time-1;
    }
};