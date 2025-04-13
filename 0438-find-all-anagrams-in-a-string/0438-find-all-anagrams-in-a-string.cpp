class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), i = 0, j = 0, cnt = 0, k = p.size();
        unordered_map<char, int> mp;
        for (auto it : p) mp[it]++;
        cnt = mp.size();
        while (j < n){
            if (mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if (mp[s[j]] == 0) cnt--;
            }
            if (j-i+1 < k){
                j++;
                continue;
            }
            if (cnt == 0){
                ans.push_back(i);
            }
            if (mp.find(s[i]) != mp.end()){
                if (mp[s[i]] == 0) cnt++;
                mp[s[i]]++;
            }
            j++, i++;
        }
        return ans;
    }
};