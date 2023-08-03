class Solution {
public:
    int recursion(int indx, bool buy, int cap,vector<int>& prices){
        if (indx == prices.size() ||  cap == 0) return 0;
        int profit = 0;
        if (buy){
            profit = max(-prices[indx] + recursion(indx+1, !buy, cap,prices), 0 + recursion(indx+1, buy, cap, prices));
        }
        else{
            profit = max(prices[indx] + recursion(indx+1, !buy, cap-1, prices), 0 + recursion(indx+1, buy, cap,prices));
        }
        return profit;
    }

    int memoization(int indx, bool buy, int cap,vector<int>& prices, vector<vector<vector<int>>>& dp){
        if (indx == prices.size() ||  cap == 0) return 0;
        if (dp[indx][buy][cap]!=-1) return dp[indx][buy][cap];
        int profit = 0;
        if (buy){
            profit = max(-prices[indx] + memoization(indx+1, !buy, cap,prices,dp), 0 + memoization(indx+1, buy, cap, prices,dp));
        }
        else{
            profit = max(prices[indx] + memoization(indx+1, !buy, cap-1, prices,dp), 0 + memoization(indx+1, buy, cap,prices,dp));
        }
        return dp[indx][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return memoization(0, 1, k, prices, dp);
    }
};