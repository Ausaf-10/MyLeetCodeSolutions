class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int full = 0, empty = numBottles, ans = numBottles;
        while (full > 0 || empty >= numExchange){
            // if (full == 0 && empty < numExchange) break;
            if (empty >= numExchange){
                empty-=numExchange;
                numExchange++;
                full++;
            }
            else{
                ans += full;
                empty+=full;
                full = 0;
            }
        }
        return ans;
    }
};