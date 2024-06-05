class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0, n = s.size(), mini = 1e9, startIndx = -1;
        string ans = s, temp = "";
        unordered_map<int, int> mp;
        for (auto it : t) mp[it]++;
        int cnt = mp.size(); 
        while (j<n){
            if (mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if (mp[s[j]] == 0) cnt--;
            }
            while (cnt == 0 && i<=j){
                if (j-i+1 < mini){
                    mini = j-i+1;
                    startIndx = i;
                }
                if (mp.find(s[i]) != mp.end()){
                    if (mp[s[i]] == 0) cnt++;
                    mp[s[i]]++;
                }
                i++;
            }
            j++;
        }
        return mini == 1e9 ? "" : s.substr(startIndx, mini);
    }
};