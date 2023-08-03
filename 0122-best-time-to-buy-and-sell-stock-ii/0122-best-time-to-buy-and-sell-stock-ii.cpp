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

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2,-1));
        return memoization(0, 1, prices, dp);
    }
};