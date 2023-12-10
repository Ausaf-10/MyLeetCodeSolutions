class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> newMat(col, vector<int>(row,0));
        cout << row << " " << col;
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                newMat[j][i] = mat[i][j];
            }
        }
        
        return newMat;
    }
};