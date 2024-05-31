class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int ans = -1;
        for (auto it : nums){
            int value = abs(it);
            if (value > ans && st.contains(-it)){
                ans = max(ans, value);
            }
            st.insert(it);
        }
        return ans;
    }
};