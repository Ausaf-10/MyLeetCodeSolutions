class Solution {
public:
    // COUNT SUBSET SUM EQUALS K
    int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(ind==0){
            if(nums[0]==0 && target==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            return 0;
        }

        if(dp[ind][target]!= -1) return dp[ind][target];

        int notTake = f(ind-1,target,nums,dp);
        int take = 0;
        
        if(nums[ind] <=target)
            take = f(ind-1,target-nums[ind],nums,dp);
        
        return dp[ind][target] = (take + notTake);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i=0; i<n; i++)
            totSum += nums[i];
        
        if(totSum-target<0 || (totSum-target)%2==1 )
            return 0;
        
        int k = (totSum-target)/2;

        vector<vector<int>> dp(n, vector<int> (k+1,-1));
        return f(n-1,k,nums,dp);
    }
};