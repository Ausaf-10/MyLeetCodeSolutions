class Solution {
public:
    int recursion(vector<int> &arr, int target, int indx){
        if (indx == 0){
            if (target % arr[0] == 0) return target / arr[0];
            return 1e9;
        }
        int notPick = 0 + recursion(arr, target, indx-1);
        int pick = 1e9;
        if (arr[indx] <= target){
            pick = 1 + recursion(arr, target-arr[indx], indx);
        }
        return min(notPick, pick);
    }
    int memoization(vector<int> &arr, int target, int indx, vector<vector<int>>& dp){
        if (indx == 0){
            if (target % arr[0] == 0) return target / arr[0];
            return 1e9;
        }
        if (dp[indx][target] != -1) return dp[indx][target];
        int notPick = 0 + memoization(arr, target, indx-1, dp);
        int pick = 1e9;
        if (arr[indx] <= target){
            pick = 1 + memoization(arr, target-arr[indx], indx, dp);
        }
        return dp[indx][target]=min(notPick, pick);
    }
    int tabulation(vector<int>& arr, int amount){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,1e9));
        for (int i=0; i<=amount; i++){
            if (i % arr[0] == 0) dp[0][i] = i/arr[0];
        }

        for (int indx=1; indx<n; indx++){
            for (int target=0; target<=amount; target++){
                int notPick = 0 + dp[indx-1][target] ;
                int pick = 1e9;
                if (arr[indx] <= target){
                    pick = 1 + dp[indx][target-arr[indx]] ;
                }
                dp[indx][target]=min(notPick, pick);
            }
        }

        return dp[n-1][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        // // int x = memoization(coins, amount, n-1, dp);
        int x = tabulation(coins, amount);
        return x == 1e9 ? -1 : x;
    }
};