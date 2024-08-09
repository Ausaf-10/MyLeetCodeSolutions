class Solution {
public:
    int n;
    int longestArithSeqLength(vector<int>& arr) {
        n = arr.size();
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        for (int indx=1; indx<n; indx++){
            for (int j=0; j<indx; j++){
                int diff = arr[indx] - arr[j] + 500;
                dp[indx][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
                maxi = max(maxi, dp[indx][diff]);
            }
        }
        return maxi;
    }
};