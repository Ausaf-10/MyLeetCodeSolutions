class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        for (int i=0; i<n; i++){
            int mini = 1e9, col = -1;
            for (int j=0; j<m; j++){
                if (mat[i][j] < mini){
                    mini = mat[i][j];
                    col = j;
                }
            }
            int maxi = -1e9;
            for (int row=0; row<n; row++){
                maxi = max(maxi, mat[row][col]);
            }
            if (maxi == mini) ans.push_back(maxi);
        }
        return ans;
    }
};