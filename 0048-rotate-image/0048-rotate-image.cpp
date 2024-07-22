class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> newMat(n, vector<int>(n,0));
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                newMat[i][j] = mat[n-j-1][i];
            }
        }
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                mat[i][j] = newMat[i][j];
            }
        }
        return;
    }
};