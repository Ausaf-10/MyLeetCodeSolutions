class Solution {
public:
    int n ;
    int recursion(vector<int>& arr, int target, int indx){
        if (indx == 0){
            if (target % arr[0] == 0) return 1;
            return 0;
        }
        int notPick = recursion(arr, target, indx-1);
        int pick = 0;
        if (arr[indx] <= target){
            pick = recursion(arr, target-arr[indx], indx);
        }
        return pick + notPick;
    }
    int memoization(vector<int>& arr, int target, int indx, vector<vector<int>>& dp){
        if (indx == 0){
            if (target % arr[0] == 0) return 1;
            return 0;
        }
        if (dp[indx][target] != -1) return dp[indx][target];
        int notPick = memoization(arr, target, indx-1, dp);
        int pick = 0;
        if (arr[indx] <= target){
            pick = memoization(arr, target-arr[indx], indx, dp);
        }
        return dp[indx][target] = pick + notPick;
    }
    int tabulation(int k, vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k+1,0));
        for (int target=0; target<=k; target++){
            if (target%arr[0] == 0) dp[0][target] = 1;
        }
        for (int indx = 1; indx<n; indx++){
            for (int target=0; target<=k; target++){
                int notPick = dp[indx-1][target];
                int pick = 0;
                if (arr[indx] <= target){
                    pick = dp[indx][target-arr[indx]];
                }
                dp[indx][target] = pick + notPick;
            }
        }
        return dp[n-1][k];
    }
    int change(int target, vector<int>& arr) {
        n = arr.size();
        if (target == 0) return 1;
        // vector<vector<int>> dp(n, vector<int>(target+1,
        return tabulation(target, arr);
    }
};