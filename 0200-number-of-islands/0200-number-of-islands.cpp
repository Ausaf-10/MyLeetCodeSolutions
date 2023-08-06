class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int row, int col,vector<vector<char>>& vis, int n, int m){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1' && vis[row][col]=='0') 
        return true;
        return false;
    }
    void bfs(vector<vector<char>>& grid, int row, int col,vector<vector<char>>& vis){
        int n = grid.size(), m = grid[0].size();
       
        queue<pair<int,int>> q;
        q.push({row,col});
        vis[row][col] = '1';

        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,1,0,-1};

            for (int i=0; i<4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if (isValid(grid,nrow,ncol,vis, n, m)){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = '1';
                }
            }
        }

        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<char>> vis(n, vector<char>(m,'0'));
        int cnt = 0; 
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == '1' && vis[i][j] == '0'){
                    bfs(grid, i, j, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};