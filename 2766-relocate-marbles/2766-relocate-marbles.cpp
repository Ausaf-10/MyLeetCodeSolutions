class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> ans;
        map<int,int> mp;
        for (int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for (int i=0; i<moveFrom.size(); i++){
            int freq = mp[moveFrom[i]];
            mp[moveFrom[i]] = 0;
            mp[moveTo[i]]+=freq;
        }
        for (auto it : mp){
            if (it.second > 0){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};