class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto it : arr){
            mp[it]++;
        }
        int cnt = 1;
        for (auto it : arr){
            if (mp[it] == 1 && cnt == k){
                return it;
            }
            else if (mp[it] == 1){
                cnt++;
            }
        }
        return "";
    }
};