class Solution {
public: 
    int recursion(int indx, int target, vector<int>& coins){
        // BASE CASE
        if (indx == 0){
            if (target % coins[indx] == 0) return target / coins[indx];
            return 1e9;
        }   
        int notPick = 0 + recursion(indx-1,target, coins);
        int pick = INT_MAX;
        if (coins[indx]<=target) pick = 1 + recursion(indx,target - coins[indx], coins);
        return min(pick,notPick);

    }

    int memoization(int indx, int target, vector<int>& coins, vector<vector<int>>& dp){
        if (indx == 0){
            if (target % coins[0] == 0) return target / coins[indx];
            return 1e9;
        }   

        if (dp[indx][target] !=-1) return dp[indx][target];

        int notPick = 0 + memoization(indx-1,target, coins, dp);
        int pick = INT_MAX;
        if (coins[indx]<=target) pick = 1 + memoization(indx,target - coins[indx], coins, dp);
        return dp[indx][target] = min(pick,notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int> (amount + 1, -1));
        // int ans = memoization(n-1, amount, coins, dp);
        // return ans == 1e9 ? -1 : ans;

        vector<vector<int>> dp(n, vector<int> (amount + 1, 1e9)); // dp[indx][amount];
        // BASE CASE
        for (int i=0; i<=amount; i++){
            if (i % coins[0] == 0) dp[0][i] = i / coins[0];
        }
        for (int indx=1; indx<n; indx++){
            for (int target = 0; target <= amount; target++){
                int notPick = 0 + dp[indx-1][target];
                
                int pick = INT_MAX;
                if (coins[indx]<=target) pick = 1 + dp[indx][target-coins[indx]];

                dp[indx][target] = min(pick,notPick);
            }
        }
        int ans = dp[n-1][amount];
        return ans == 1e9 ? -1 : ans;

    }
};