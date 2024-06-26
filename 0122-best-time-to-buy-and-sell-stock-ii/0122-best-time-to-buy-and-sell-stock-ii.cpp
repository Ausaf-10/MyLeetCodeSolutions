class Solution {
public:
    int n;
    int recursion(int indx, bool buy, vector<int>& arr){
        if (indx == n) return 0;
        if (buy){
            int buying = -arr[indx] + recursion(indx+1, !buy, arr);
            int notBuying = 0 + recursion(indx+1, buy, arr);
            return max(buying, notBuying);
        }
        else{
            int sell = arr[indx] + recursion(indx+1, !buy, arr);
            int notSell = 0 + recursion(indx+1, buy, arr);
            return max(sell, notSell);
        }
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

    int tabulation(vector<int>& arr){
        vector<vector<int>> dp (n+1, vector<int>(2,0));
        for (int indx=n-1; indx>=0; indx--){
            for (int buy=0; buy<=1; buy++){
                if (buy){
                    int buying = -arr[indx] + dp[indx+1][!buy] ;
                    int notBuying = 0 + dp[indx+1][buy];
                    dp[indx][buy] = max(buying, notBuying);
                }
                else{
                    int sell = arr[indx] + dp[indx+1][!buy];
                    int notSell = 0 + dp[indx+1][buy];
                    dp[indx][buy] = max(sell, notSell);
                }
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& arr) {
        n = arr.size();
        // vector<vector<int>> dp (n+1, vector<int>(2,-1));
        // return memoization(0, 1, prices, dp);
        // return recursion(0, 1, arr);
        return tabulation(arr);
    }
};