class Solution {
public:
    int n;
    int tabulation(vector<int>& prices, int k){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for (int indx=n-1; indx>=0; indx--){
            for (int buy = 0; buy<=1; buy++){
                for (int cnt = 0; cnt < k; cnt++){
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
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        return tabulation(prices, k);
    }
};