class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rowCount(n,0), colCount(m,0);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 0) continue;
                rowCount[i]++;
                colCount[j]++;
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 0) continue;
                if (colCount[j] > 1 || rowCount[i] > 1) continue;
                cnt++;
            }
        }
        return cnt;
    }
};