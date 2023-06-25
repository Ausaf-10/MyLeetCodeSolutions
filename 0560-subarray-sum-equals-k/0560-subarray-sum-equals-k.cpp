class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int preSum=0,cnt=0;
        for (int i=0; i<nums.size(); i++){
            mp[preSum]++;
            preSum += nums[i];

            int rem = preSum - k;

            if (mp.find(rem) != mp.end()){
                cnt+=mp[rem];
            }
        }
        return cnt;
    }
};