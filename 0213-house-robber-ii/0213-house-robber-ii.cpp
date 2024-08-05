class Solution {
public:
    int n;
    int tabulation(vector<int>& arr){
        // not including the last guy!!
        vector<int> dp(n,-1);
        dp[0] = arr[0];
        for (int indx = 1; indx<n-1; indx++){
            int pick = arr[indx];
            int notPick = 0 + dp[indx - 1];
            if (indx > 1) pick += dp[indx-2];
            dp[indx] = max(pick, notPick);
        }
        return dp[n-2];
    }
    int tabulation2(vector<int>& arr){
        // including the last guy
        vector<int> dp(n,0);
        dp[1] = arr[1];
        for (int indx = 2; indx<n; indx++){
            int pick = arr[indx];
            int notPick = 0 + dp[indx - 1];
            if (indx > 1) pick += dp[indx-2];
            dp[indx] = max(pick, notPick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if (n == 1) return nums[0];
        return max(tabulation(nums), tabulation2(nums));
    }
};