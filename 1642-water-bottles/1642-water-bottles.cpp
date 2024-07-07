class Solution {
public:
    int numWaterBottles(int full, int numExchange) {
        int empty = full, ans = full;
        full = 0;
        while (full > 0 || empty >= numExchange){
            while (empty >= numExchange){
                empty -= numExchange;
                full++;
            }
            ans += full;
            empty += full;
            full = 0;
        }
        return ans;
    }
};