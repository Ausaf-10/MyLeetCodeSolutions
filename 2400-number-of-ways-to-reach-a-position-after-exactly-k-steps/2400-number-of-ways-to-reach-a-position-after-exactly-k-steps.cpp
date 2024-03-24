const int MOD = 1e9+7;
class Solution {
public:
    int recursion(int indx, int endPos, int k){
        if (k == 0){
            if (indx == endPos) return 1;
            return 0;
        }
        int left = 0;
        left = recursion(indx-1, endPos, k-1);

        int right = 0;
        right = recursion(indx + 1, endPos, k-1);

        return left + right;
    }
    int memoization(int indx, int endPos, int k, vector<vector<int>>& dp){
        if (k == 0){
            if (indx == endPos) return 1;
            return 0;
        }
        if (dp[indx+1000][k]!=-1) return dp[indx+1000][k]; 
        int left = 0;
        left = memoization(indx-1, endPos, k-1, dp)%MOD;

        int right = 0;
        right = memoization(indx + 1, endPos, k-1, dp)%MOD;

        return dp[indx+1000][k] = (left + right)%MOD;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001, vector<int>(1001,-1));
        return memoization(startPos, endPos, k, dp);
    }
};