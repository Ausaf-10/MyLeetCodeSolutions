class Solution {
public:
    int recursion(int indx, bool buy, vector<int>& prices){
        if (indx == prices.size()) return 0;
        int profit = 0;
        if (buy){
            profit = max(-prices[indx] + recursion(indx+1, !buy, prices), 0 + recursion(indx+1, buy, prices));
        }
        else{
            profit = max(prices[indx] + recursion(indx+1, !buy, prices), 0 + recursion(indx+1, buy, prices));
        }
        return profit;
    }

    int memoization(int indx, bool buy, vector<int>& prices, vector<vector<int>>& dp){
        if (indx == prices.size()) return 0;
        if (dp[indx][buy]!=-1) return dp[indx][buy];
        int profit = 0;
        if (buy){
            profit = max(-prices[indx] + memoization(indx+1, !buy, prices, dp), 0 + memoization(indx+1, buy, prices, dp));
        }
        else{
            profit = max(prices[indx] + memoization(indx+1, !buy, prices, dp), 0 + memoization(indx+1, buy, prices, dp));
        }
        return dp[indx][buy] = profit;
    }

    int tabulation(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2,-1));
        dp[n][0] = 0, dp[n][1] = 0;
        for (int i = n-1; i>=0; i--){
            for (int j=0; j<2; j++){
                int profit = 0;
                if (j){
                    profit = max(-prices[i] + dp[i+1][!j], 0 + dp[i+1][j]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][!j], 0 + dp[i+1][j]);
                }
                dp[i][j] = profit;
            }
        } 

        return dp[0][1];
    }
    
    int spaceOptimization(vector<int>& prices){
        int n = prices.size();
        vector<int> prev(2,0);
        prev[0] = 0, prev[1] = 0;
        for (int i=n-1; i>=0; i--){
            vector<int> temp(2,0);
            for (int j=0; j<2; j++){
                int profit = 0;
                if (j){
                    profit = max(-prices[i] + prev[!j], 0 + prev[j]);
                }
                else{
                    profit = max(prices[i] + prev[!j], 0 + prev[j]);
                }
                temp[j] = profit;
            }
            prev = temp;
        }

        return prev[1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2,-1));
        return spaceOptimization(prices);
    }
};