class Solution {
public:
    int n;
    int recursion(int indx, int target, vector<int>& arr){
        if (target == 0) return 0;
        if (indx == 0){
            if (target == arr[0]) return 1;
            return -1e9;
        }
        int notPick = 0 + recursion(indx-1, target, arr);
        int pick = -1e9;
        if (arr[indx] <= target) pick = 1 + recursion(indx-1, target-arr[indx], arr);
        return max(pick, notPick);
    }
    int memoization(int indx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if (target == 0) return 0;
        if (indx == 0){
            if (target == arr[0]) return 1;
            return -1e9;
        }
        if (dp[indx][target]!=-1) return dp[indx][target];
        int notPick = 0 + memoization(indx-1, target, arr, dp);
        int pick = -1e9;
        if (arr[indx] <= target) pick = 1 + memoization(indx-1, target-arr[indx], arr, dp);
        return dp[indx][target] = max(pick, notPick);
    }
    int lengthOfLongestSubsequence(vector<int>& arr, int target) {
        n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1,-1));
        int x = memoization(n-1, target, arr, dp);
        return x <= -1e7 ? -1 : x;   
    }
};