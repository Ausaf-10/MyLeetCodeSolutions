class Solution {
public:
    bool isValid(vector<vector<int>>& mat, int row, int col,vector<vector<int>>& vis, int n,
    int m){
        if (row>=0 && row<n && col>=0 && col<m && mat[row][col] == 1 && vis[row][col] == 0) return true;
        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        
        vector<vector<int>> newMat(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m,0));

        queue<pair<int,int>> q;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    newMat[i][j] = 0;
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
                for (int i=0; i<4; i++){
                    int nrow = delrow[i] + row;
                    int ncol = delcol[i] + col;

                    if (isValid(mat, nrow, ncol, vis,n, m)){
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                        newMat[nrow][ncol] = dis;
                    }
                }

            }
            
            dis++;
        
        }

        return newMat;

    }
};