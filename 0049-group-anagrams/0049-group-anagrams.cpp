class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>> ans;
        if (s.size() == 0) return ans; 
        unordered_map<string, vector<string>> mp;
        for (int i=0; i<s.size(); i++){
            string str = s[i];
            sort(str.begin(), str.end());
            mp[str].push_back(s[i]);
        }
        for (auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};