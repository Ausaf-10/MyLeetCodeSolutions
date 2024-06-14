class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(1000000, 0);
        unordered_map<int ,int> mp;
        for (auto it : arr){
            mp[it]++;
            ans[it]++;
        }

        int res = 0;
        for (auto it : mp){
            if (it.second == 1) continue;
            int freq = it.second, ele = it.first, cnt = 0;
            for (int j=ele+1; j<ans.size(); j++){
                if (ans[j] == 0){
                    res += j-ele;
                    ans[j] = 1;
                    cnt++;
                }
                if (cnt == freq-1) break;
            }
        }
        return res;
    }
};