class Solution {
public:
    int recursion(int indx, bool buy, vector<int>& prices, int fee){
        if (indx == prices.size()) return 0;
        int profit = 0;
        if (buy){
            profit = max(-prices[indx] + recursion(indx+1, !buy, prices, fee), 0 + recursion(indx+1, buy, prices, fee));
        }
        else{
            profit = max(prices[indx] - fee + recursion(indx+1, !buy, prices, fee), 0 + recursion(indx+1, buy, prices, fee));
        }
        return profit;
    }
    int memoization(int indx, bool buy, vector<int>& prices, int fee, vector<vector<int>>& dp){
        if (indx == prices.size()) return 0;
        if (dp[indx][buy]!=-1) return dp[indx][buy];
        int profit = 0;
        if (buy){
            profit = max(-prices[indx] + memoization(indx+1, !buy, prices, fee, dp), 0 + memoization(indx+1, buy, prices, fee, dp));
        }
        else{
            profit = max(prices[indx] - fee + memoization(indx+1, !buy, prices, fee,dp), 0 + memoization(indx+1, buy, prices, fee,dp));
        }
        return dp[indx][buy] = profit;
    }

    int tabulation(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2,0));
        for (int indx = n-1; indx>=0; indx--){
            for (int buy = 0; buy < 2; buy++){
                int profit = 0;
                if (buy){
                    profit = max(-prices[indx] + dp[indx+1][!buy], 0 + dp[indx+1][buy]);
                }
                else{
                    profit = max(prices[indx] - fee + dp[indx+1][!buy], 0 + dp[indx+1][buy]);
                }
                dp[indx][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int spaceOptimization(vector<int>& prices, int fee){
        int n = prices.size();
        vector<int> prev(2,0);
        for (int indx = n-1; indx>=0; indx--){
            vector<int> temp (2,0);
            for (int buy = 0; buy < 2; buy++){
                int profit = 0;
                if (buy){
                    profit = max(-prices[indx] + prev[!buy], 0 + prev[buy]);
                }
                else{
                    profit = max(prices[indx] - fee + prev[!buy], 0 + prev[buy]);
                }
                temp[buy] = profit;
            }
            prev = temp;
        }

        return prev[1];
    
    }

    int maxProfit(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int>(2,-1));
        return spaceOptimization(prices,fee);
    }
};