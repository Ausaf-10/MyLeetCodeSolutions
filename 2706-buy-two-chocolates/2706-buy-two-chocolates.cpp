class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int a = prices[0], b = prices[1];
        if (a + b <= money){
            return (money - (a+b));
        }
        return money;
    }
};