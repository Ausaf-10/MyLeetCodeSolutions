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

    int tabulation(vector<int>& prices, int cap){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(cap+1,0)));
        
        for (int i=n-1; i>=0; i--){
            for (int j=0; j<2; j++){
                for (int k=1; k<cap+1; k++){
                    int profit = 0;
                    if (j){
                        profit = max(-prices[i] + dp[i+1][!j][k],0 + dp[i+1][j][k]);
                    }
                    else{
                        profit =max(prices[i]+dp[i+1][!j][k-1], 0 + dp[i+1][j][k]);
                    }
                    dp[i][j][k] = profit;
                }
            }
        }

        return dp[0][1][cap];
    }

    int spaceOptimzation(vector<int>& prices, int cap){
        int n = prices.size();
        vector<vector<int>> prev (2, vector<int>(cap+1,0));

        for (int i=n-1; i>=0; i--){
            vector<vector<int>> temp (2, vector<int>(cap+1,0));
            for (int j=0; j<2; j++){
                for (int k=1; k<cap+1; k++){
                    int profit = 0;
                    if (j){
                        profit = max(-prices[i] + prev[!j][k],0 + prev[j][k]);
                    }
                    else{
                        profit =max(prices[i]+prev[!j][k-1], 0 + prev[j][k]);
                    }
                    temp[j][k] = profit;
                }
            }
            prev = temp;
        }

        return prev[1][cap];
        
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return tabulation(prices, k);
    }
};