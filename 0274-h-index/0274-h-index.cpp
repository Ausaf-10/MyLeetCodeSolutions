class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        for (int i=citations.size(); i>=0; i--){
            int cnt = 0;
            for (auto it : citations){
                if (it >= i) cnt++;
            }
            if (cnt >= i) ans = max(ans, i);
        }
        return ans;
    }
};