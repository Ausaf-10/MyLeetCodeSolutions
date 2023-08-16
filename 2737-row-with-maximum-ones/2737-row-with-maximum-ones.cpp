class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int maxCnt = 0, indx = n;
        for (int i=0; i<n; i++){
            int cnt = 0;
            for (int j = 0; j<m; j++){
                if (mat[i][j] == 1){
                    cnt++;
                }
            }
            if (cnt > maxCnt){
                maxCnt = cnt;
                indx = i;
            }
        }
        if (maxCnt == 0) return {0,0};
        
        return {indx,maxCnt};
    }
};