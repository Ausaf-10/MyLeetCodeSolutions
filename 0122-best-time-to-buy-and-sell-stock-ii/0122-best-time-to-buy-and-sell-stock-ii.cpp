class Solution {
public:
    int n;
    int recursion(int indx, int buy, vector<int>& prices){
        if (indx == n) return 0;
        // ALREADY BOUGHT
        if (buy){
            int sell = prices[indx] + recursion(indx+1, !buy, prices);
            int notSell = 0 + recursion(indx+1, buy, prices);
            return max(sell, notSell);
        }
        else{
            int buyThisDay = -prices[indx] + recursion(indx+1, !buy, prices);
            int notBuyThisDay = 0 + recursion(indx+1, buy, prices);
            return max(buyThisDay, notBuyThisDay);
        }
    }
    int tabulation(vector<int>& prices){
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for (int indx=n-1; indx>=0; indx--){
            for (int buy = 0; buy<=1; buy++){
                if (buy){
                    int sell = prices[indx] + dp[indx+1][!buy];
                    int notSell = 0 + dp[indx+1][buy];
                    dp[indx][buy] = max(sell, notSell);
                }
                else{
                    int buyThisDay = -prices[indx] + dp[indx+1][!buy];
                    int notBuyThisDay = 0 + dp[indx+1][buy];
                    dp[indx][buy] = max(buyThisDay, notBuyThisDay);
                }
            }
        }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        // return recursion(0, 0, prices);
        return tabulation(prices);
    }
};