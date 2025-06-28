class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int> mp;
        vector<int> ans(2);
        for (int i=0; i<n; i++){
            if (mp.find(target-arr[i]) != mp.end()){
                ans[0] = i, ans[1] = mp[target-arr[i]];
                break;
            }
            mp[arr[i]] = i;
        }
        return ans;
    }
};