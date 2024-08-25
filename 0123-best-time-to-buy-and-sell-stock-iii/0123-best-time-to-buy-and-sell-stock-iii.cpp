class Solution {
public:
    int n;
    int recursion(int indx, int buy, vector<int>& prices, int cnt){
        if (indx == n || cnt == 2) return 0;
        // ALREADY BOUGHT
        if (buy){
            int sell = prices[indx] + recursion(indx+1, !buy, prices, cnt+1);
            int notSell = 0 + recursion(indx+1, buy, prices, cnt);
            return max(sell, notSell);
        }
        else{
            int buyThisDay = -prices[indx] + recursion(indx+1, !buy, prices, cnt);
            int notBuyThisDay = 0 + recursion(indx+1, buy, prices, cnt);
            return max(buyThisDay, notBuyThisDay);
        }
    }
    int tabulation(vector<int>& prices){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int indx=n-1; indx>=0; indx--){
            for (int buy = 0; buy<=1; buy++){
                for (int cnt = 0; cnt < 2; cnt++){
                    if (buy){
                        int sell = prices[indx] + dp[indx+1][!buy][cnt+1];
                        int notSell = 0 + dp[indx+1][buy][cnt];
                        dp[indx][buy][cnt] = max(sell, notSell);
                    }
                    else{
                        int buyThisDay = -prices[indx] + dp[indx+1][!buy][cnt];
                        int notBuyThisDay = 0 + dp[indx+1][buy][cnt];
                        dp[indx][buy][cnt] = max(buyThisDay, notBuyThisDay);
                    }
                }
            }
        }
        return dp[0][0][0];
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        // return recursion(0, 0, prices, 0);
        return tabulation(prices);
    }
};