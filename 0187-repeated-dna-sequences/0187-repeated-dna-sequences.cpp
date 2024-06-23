class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size(), i = 0, j = 0;
        string temp;
        unordered_map<string, int> mp;
        vector<string>ans;
        while (j<n){
            temp.push_back(s[j]);
            if (j-i+1 < 10) j++;
            else{
                mp[temp]++;
                temp.erase(0,1);
                i++,j++;
            }
        }
        for (auto it: mp){
            if (it.second > 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};