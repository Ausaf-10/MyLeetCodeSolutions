class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>> maxHeap;
        vector<int> ans;
        unordered_map<int,int> mp;

        for (int i=0; i<nums.size(); i++) mp[nums[i]]++;

        for (auto number:mp){
            maxHeap.push({-1*number.second,number.first});
        }

        while (!maxHeap.empty()){
            int freq = abs(maxHeap.top().first);
            int currentValue = maxHeap.top().second;

            for (int i=0; i<freq; i++){
                ans.push_back(currentValue);
            }

            maxHeap.pop();
        }

        return ans;
    }
};