class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> mat(n, vector<int>(m,0));
        int i = 0, j = 0;
        while (i<n && j<m){
            int mini = min(rowSum[i], colSum[j]);
            rowSum[i]-=mini, colSum[j] -= mini;
            mat[i][j] = mini;
            if (!rowSum[i]) i++;
            if (!colSum[j]) j++;
        }
        return mat;
    }
};