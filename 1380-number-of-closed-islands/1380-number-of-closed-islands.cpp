class Solution {
public:
    int n,m;
    bool isValid(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &vis){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 0 && !vis[row][col]) return true;
        return false;
    }
    void bfs(vector<vector<int>>& grid, int sr, int sc, vector<vector<int>> &vis){
        queue<pair<int,int>> q; vis[sr][sc] = 1; q.push({sr,sc});
        while (!q.empty()){
            int row = q.front().first, col = q.front().second;
            q.pop();

            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};
            for (int i=0; i<4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                if (isValid(grid,nrow,ncol,vis)){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return ;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (i == 0 || i == n-1 || j == 0 | j == m-1){
                    if (grid[i][j] == 0){
                        bfs(grid,i,j,vis);
                    }
                }
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 0 && !vis[i][j]){
                    bfs(grid,i,j,vis);
                    cnt++;
                }
            } 
        }

        return cnt;
    }
};