class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,mn=prices[0];
        for (int i=1; i<prices.size(); i++){
            int cost = prices[i] - mn;
            profit=max(profit,cost);
            mn=min(mn,prices[i]);
        }
        return profit;
    }
};