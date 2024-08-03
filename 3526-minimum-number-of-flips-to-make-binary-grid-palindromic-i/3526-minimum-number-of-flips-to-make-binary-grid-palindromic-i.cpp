class Solution {
public:
    int n,m;
    int makeColPallindrome(vector<vector<int>>& mat){
        int ans = 0;
        for (int j = 0; j < n; j++){
            int cnt = 0;
            for (int i = 0; i<m/2; i++){
                if (mat[i][j] != mat[m-i-1][j]) cnt++;
            }
            ans += cnt;
        }
        return ans;
    }
    int makeRowPallindrome(vector<vector<int>>& mat){
        int ans = 0;
        for (int i = 0; i < m; i++){
            int cnt = 0;
            for (int j = 0; j<n/2; j++){
                if (mat[i][j] != mat[i][n-1-j]) cnt++;
            }
            ans += cnt;
        }
        return ans;
    }
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        // if (n == 1 ) return 0;
        return min(makeColPallindrome(mat), makeRowPallindrome(mat));
    }
};