class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        vector<int> ans;
        for (auto it : arr1) mp[it]++;
        for (int i=0; i<arr2.size(); i++){
            int freq = mp[arr2[i]];
            for (int j=0; j<freq; j++){
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        for (auto it : mp){
            int freq = it.second;
            for (int j=0; j<freq; j++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};