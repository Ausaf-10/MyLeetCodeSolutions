class Solution {
public:
    int recursion(int indx, int target, vector<int>& coins){
        if (target == 0) return 1;
        if (indx == 0){
            return (target % coins[0] == 0);
        }
        int notPick = recursion(indx-1, target, coins);
        int pick = 0;
        if (coins[indx] <= target) pick = recursion(indx, target - coins[indx], coins);
        return pick + notPick;
    }

    int memoization(int indx, int target, vector<int>& coins, vector<vector<int>>& dp){
        if (target == 0) return 1;
        if (indx == 0){
            if (target % coins[0] == 0) return 1;
            return 0;
        }
        
        if (dp[indx][target]!=-1) return dp[indx][target];
        
        int notPick = memoization(indx-1, target, coins, dp);
        int pick = 0;
        if (coins[indx] <= target) pick = memoization(indx, target - coins[indx], coins, dp);
        return dp[indx][target] = pick + notPick;
    }

    int tabulation(int amount, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,0));
        for (int i=0; i<n; i++) dp[i][0] = 1;
        for (int j=0; j<=amount; j++){
            dp[0][j] = j % coins[0] == 0;
        }

        for (int indx=1; indx<n; indx++){
            for (int target=1; target<=amount; target++){
                int notPick = dp[indx-1][target];
                int pick = 0;
                if (coins[indx] <= target) pick = dp[indx][target - coins[indx]] ;
                dp[indx][target] = pick + notPick;
            }
        }
        return dp[n-1][amount];
    }

    int spaceOptimization(int amount, vector<int>& coins){
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        prev[0] = 1;
        for (int j=1; j<=amount; j++) prev[j] = j%coins[0] == 0;

        for (int indx=1; indx<n; indx++){
            vector<int> temp(amount+1,0);
            temp[0] = 1;
            for (int target = 1; target<=amount; target++){
                int notPick = prev[target];
                int pick = 0;
                if (coins[indx] <= target) pick = temp[target - coins[indx]] ;
                temp[target] = pick + notPick;
            }
            prev = temp;
        }
        return prev[amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return spaceOptimization(amount, coins);
    }
};