class Solution {
public:
    int recursion(int indx, int prevIndx, vector<int>& arr){
        if (indx == arr.size()) return 0;
        int len = 0 + recursion(indx+1, prevIndx, arr);
        if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
            len = max(len, 1 + recursion(indx+1, indx, arr));
        } 

        return len;
    }

    int memoization(int indx, int prevIndx, vector<int>& arr, vector<vector<int>>& dp){
        if (indx == arr.size()) return 0;
        if (dp[indx][prevIndx+1]!=-1) return dp[indx][prevIndx+1];

        int len = 0 + memoization(indx+1, prevIndx, arr, dp);
        if (prevIndx == -1 || arr[indx] > arr[prevIndx]){
            len = max(len, 1 + memoization(indx+1, indx, arr, dp));
        } 

        return dp[indx][prevIndx + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return memoization(0, -1, nums, dp);    
        // return recursion(0, -1, nums);
    }
};