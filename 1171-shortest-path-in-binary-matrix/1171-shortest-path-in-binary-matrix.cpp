class Solution {
public:
    bool isValid(vector<vector<int>> &grid, int row, int col, int n, int m){
        if (row>=0 && row<n && col>=0 && col<m && grid[row][col] == 0) return true;
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        
        if (mat[0][0] || mat[n-1][m-1]) return -1;
        
        queue<pair<int,int>> q; q.push({0,0}); mat[0][0] = -1;
        int dis = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                auto node = q.front(); q.pop();
                int row = node.first, col = node.second;
                
                if (row == n-1 && col == m-1) return dis+1;
                
                for (int delrow=-1; delrow<=1; delrow++){
                    for (int delcol=-1; delcol<=1; delcol++){
                        int nrow = delrow + row, ncol = delcol + col;
                        if (isValid(mat, nrow, ncol, n, m)){
                            q.push({nrow,ncol});
                            mat[nrow][ncol] = -1;
                        }
                    }
                }
            }
            dis++;
        }
        return -1;
    }
};