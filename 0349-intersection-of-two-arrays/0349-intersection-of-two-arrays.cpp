class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int, int> mp;
        for (auto &it : nums1){
            mp[it]++;
        }
        for (auto it : nums2){
            if (mp.find(it) != mp.end()){
                ans.push_back(it);
                mp.erase(it);
            }
        }
        return ans;
    }
};