class Solution {
public:
    bool recursion(int indx, int target, vector<int>& arr){
        if (target == 0) return true;
        if (indx == 0) return arr[0] == target;

        bool notPick = recursion(indx-1,target,arr);
        bool pick = false;
        if (arr[indx] <= target) pick = recursion(indx-1,target-arr[indx],arr);

        return pick || notPick;
    }

    bool memoization(int indx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if (target == 0) return true;
        if (indx == 0) return arr[0] == target;
        if (dp[indx][target]!=-1) return dp[indx][target];

        bool notPick = memoization(indx-1,target,arr,dp);
        bool pick = false;
        if (arr[indx] <= target) pick = memoization(indx-1,target-arr[indx],arr,dp);

        return dp[indx][target] = pick || notPick;
    }
    
    int getSum(vector<int>& nums){
        int sum = 0;
        for (int i=0; i<nums.size(); i++) sum+=nums[i];
        return sum;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = getSum(nums);

        if (totSum % 2 != 0) return false;

        int target = totSum/2;

        vector<vector<int>> dp(n , vector<int>(target+1,-1));

        return memoization(n-1,target,nums,dp);    
    }
};