class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi = 0;
        for (int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for (auto it : mp) maxi = max(maxi, it.second);
        int cnt = 0;
        for (auto it : mp){
            if (it.second == maxi) cnt+=it.second; 
        }
        return cnt;
    }
};