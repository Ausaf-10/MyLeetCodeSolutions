class Solution {
public:
    int mySqrt(int n){
        int low = 1, high = n;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (mid*mid>n) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
    int recursion(int indx, int target){
        if (indx == 1){
            if (target % 1 == 0) return target / 1;
            return 1e9;
        }  
        int notPick = 0 + recursion(indx-1, target);
        int pick = 1e9;
        if (indx*indx <= target) pick = 1 + recursion(indx, target-(indx*indx));
        return min(notPick, pick);
    }
    int memoization(int indx, int target, vector<vector<int>>& dp){
        if (indx == 1){
            if (target % 1 == 0) return target / 1;
            return 1e9;
        }  
        if (dp[indx][target]!=-1) return dp[indx][target];
        int notPick = 0 + memoization(indx-1, target, dp);
        int pick = 1e9;
        if (indx*indx <= target) pick = 1 + memoization(indx, target-(indx*indx), dp);
        return dp[indx][target] = min(notPick, pick);
    }
    int numSquares(int n) {
        int indx = mySqrt(n);
        vector<vector<int>> dp(indx+1, vector<int>(n+1,-1));
        return memoization(indx, n, dp);
    }
};