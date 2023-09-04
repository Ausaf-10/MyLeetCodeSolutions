class cmp{
    public:
        bool operator()(pair<int,int>& a, pair<int,int>& b){
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp > minHeap;
        unordered_map<int,int> mp;
        for (auto it : nums) mp[it]++;

        for (auto it : mp){
            int freq = it.second , value = it.first;
            minHeap.push({freq,value});
        }

        vector<int> ans;

        while (!minHeap.empty()){
            int node = minHeap.top().second, freq = minHeap.top().first;
            minHeap.pop();
            for (int i=0; i<freq; i++){
                ans.push_back(node);
            }

        }

        return ans;
    
    }
};