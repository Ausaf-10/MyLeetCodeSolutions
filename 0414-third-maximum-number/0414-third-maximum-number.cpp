class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> st;
        int maxi = -1e9;
        for (auto it : nums){
            maxi = max(maxi, it);
            st.insert(it);
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto it : st){
            pq.push(it);
            if (pq.size() > 3) pq.pop();
        }
        if (pq.size() == 3) return pq.top();
        
        return maxi;
    }
};