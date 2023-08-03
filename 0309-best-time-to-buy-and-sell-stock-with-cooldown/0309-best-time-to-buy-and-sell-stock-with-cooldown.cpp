class Solution {
public:
    int recursion(int indx, bool buy, vector<int>& prices){
        if (indx >= prices.size()) return 0;
        int profit = 0;
        if (buy){
            profit = max(-prices[indx] + recursion(indx+1, !buy, prices), 0 + recursion(indx+1, buy, prices));
        }
        else{
            profit = max(prices[indx] + recursion(indx+2, !buy, prices), 0 + recursion(indx+1, buy, prices));
        }
        return profit;
    }

    int memoization(int indx, bool buy, vector<int>& prices, vector<vector<int>>& dp){
        if (indx >= prices.size()) return 0;
        if (dp[indx][buy]!=-1) return dp[indx][buy];
        int profit = 0;
        if (buy){
            profit = max(-prices[indx] + memoization(indx+1, !buy, prices,dp), 0 + memoization(indx+1, buy, prices, dp));
        }
        else{
            profit = max(prices[indx] + memoization(indx+2, !buy, prices, dp), 0 + memoization(indx+1, buy, prices, dp));
        }
        return dp[indx][buy] = profit;
    }

    int tabulation(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));
    
        for (int indx=n-1; indx>=0; indx--){
            for (int buy=0; buy<2; buy++){
                int profit = 0;
                if (buy){
                profit = max(-prices[indx] + dp[indx+1][!buy], 0 + dp[indx+1][buy]);
                }
                else{
                    profit = max(prices[indx] + dp[indx+2][!buy], 0 + dp[indx+1][buy]);
                }
                dp[indx][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        return tabulation(prices);
    }
};