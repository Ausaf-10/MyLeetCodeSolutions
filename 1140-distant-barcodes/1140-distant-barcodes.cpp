class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int, int> mp;
        for (auto it : arr) mp[it]++;
        for (auto it : mp){
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        auto block = pq.top(); pq.pop();
        ans.push_back(block.second);
        block.first--;

        while (!pq.empty()){
            auto node = pq.top(); pq.pop();
            ans.push_back(node.second);
            node.first--;

            if (block.first != 0) pq.push(block);
            block = node;
        }
        return ans;
    }
};