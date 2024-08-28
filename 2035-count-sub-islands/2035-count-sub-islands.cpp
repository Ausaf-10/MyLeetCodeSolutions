class Solution {
public:
    int n,m;
    vector<vector<int>> dir = {{-1,0}, {0,1}, {1,0}, {0, -1}};
    bool isValidIsland(int row, int col, vector<vector<int>>& mat1, vector<vector<int>>& vis){
        if (row>=0 && row<n && col>=0 && col<m && !vis[row][col] && mat1[row][col]) return true;
        return false;
    }
    void visitIslands(int row, int col, vector<vector<int>>& mat1, vector<vector<int>>& vis){
        vis[row][col] = 1;
        for (auto it : dir){
            int nrow = it[0] + row, ncol = it[1] + col;
            if (isValidIsland(nrow, ncol, mat1, vis)){
                visitIslands(nrow, ncol, mat1, vis);
            }
        }
        return ;
    }
    bool isValidSubIsland(int row, int col, vector<vector<int>>& mat2){
        if (row>=0 && row<n && col>=0 && col<m && mat2[row][col] == 1) return true;
        return false;
    }

    void dfs(int row, int col, vector<vector<int>>& mat2){
        mat2[row][col] = 2;
        for (auto it : dir){
            int nrow = it[0] + row, ncol = it[1] + col;
            if (isValidSubIsland(nrow, ncol, mat2)){
                dfs(nrow, ncol, mat2);
            }
        }
        return ; 
    }

    void dfs2(int row, int col, vector<vector<int>>& mat2){
        mat2[row][col] = 3;
        for (auto it : dir){
            int nrow = it[0] + row, ncol = it[1] + col;
            if (isValidSubIsland(nrow, ncol, mat2)){
                dfs2(nrow, ncol, mat2);
            }
        }
        return; 
    }

    int countSubIslands(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        n = mat1.size(), m = mat1[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat1[i][j] && !vis[i][j]){
                    visitIslands(i, j, mat1, vis);
                }
            }
        }
        
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat2[i][j] == 1 && !vis[i][j]){
                    dfs(i, j, mat2);
                }
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat2[i][j] == 1 && vis[i][j]){
                    dfs2(i, j, mat2);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};