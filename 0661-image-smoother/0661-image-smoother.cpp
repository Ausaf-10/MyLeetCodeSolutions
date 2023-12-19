class Solution {
public:
    int n,m;
    bool isValid(vector<vector<int>>& mat, int row, int col){
        if (row >=0 && row < n && col>=0 && col < m) return true;
        return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> newMat(n, vector<int>(m,0));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int sum = 0,cnt = 0;
                for (int delrow=-1; delrow <= 1; delrow++){
                    for (int delcol=-1; delcol<=1; delcol++){
                        int nrow = i + delrow;
                        int ncol = j + delcol;
                        if (isValid(mat, nrow, ncol)){
                            sum+=mat[nrow][ncol];
                            cnt++;
                        }
                    }
                }
                newMat[i][j] = sum/cnt;
            }
        }
        return newMat;
    }
};