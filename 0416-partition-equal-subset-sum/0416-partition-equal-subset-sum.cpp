class Solution {
public:
    // bool recursion(int indx, int target, vector<int>& arr){
    //     if (target == 0) return true;
    //     if (indx == 0) return arr[0] == target;

    //     bool notPick = recursion(indx-1,target,arr);
    //     bool pick = false;
    //     if (arr[indx] <= target) pick = recursion(indx-1,target-arr[indx],arr);

    //     return pick || notPick;
    // }

    bool memoization(int indx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if (target == 0) return true;
        if (indx == 0) return arr[0] == target;
        if (dp[indx][target]!=-1) return dp[indx][target];

        bool notPick = memoization(indx-1,target,arr,dp);
        bool pick = false;
        if (arr[indx] <= target) pick = memoization(indx-1,target-arr[indx],arr,dp);

        return dp[indx][target] = pick || notPick;
    }

    // bool tabulation(int indx, int k, vector<int>& arr){
    //     int n = arr.size();
    //     vector<vector<bool>> dp(n, vector<bool> (k+1,0));
    //     // BASE CASE
    //     for (int i=0; i<n; i++) dp[i][0] = true;
    //     dp[0][arr[0]] = true;

    //     for (int indx = 1; indx < n; indx++){
    //         for (int target = 1; target<=k; target++){
    //             bool notPick = dp[indx-1][target];
    //             bool pick = false;
    //             if (arr[indx] <= target) pick = dp[indx-1][target-arr[indx]];

    //             dp[indx][target] = pick || notPick;
    //         }
    //     }

    //     return dp[n-1][k];
    // }

    bool spaceOptimization(int indx, int k, vector<int>& arr){
        int n = arr.size();
        vector<bool> prev(k+1,false);
        prev[0] = true;
        if (arr[0] <= k) prev[arr[0]] = true;
        for (int indx = 1; indx < n; indx++){
            vector<bool> temp(k+1,0);
            temp[0] = true;
            for (int target = 1; target<=k; target++){
                bool notPick = prev[target];
                bool pick = false;
                if (arr[indx] <= target) pick = prev[target-arr[indx]];

                temp[target] = pick || notPick;
            }
            prev = temp;
        }
        return prev[k];
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

        int k = totSum/2;

        // vector<vector<int>> dp(n , vector<int>(k+1,-1));
        
        return spaceOptimization(n-1,k,nums);

        
    }
};