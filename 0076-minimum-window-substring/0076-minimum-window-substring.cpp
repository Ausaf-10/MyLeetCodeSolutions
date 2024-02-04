class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for (char ch : t) mp[ch]++;
        int cnt = mp.size();
        string ans;
        int n = s.size(), mini = 1e9, indx = -1;
        int i=0,j=0;

        while (j < n){
            if (mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if (mp[s[j]]== 0) cnt--;
            }
            while (cnt == 0){
                if (j-i+1 < mini){
                    mini = j-i+1; 
                    indx = i;
                    // ans = s.substr(i,j-i+1);
                }
                if (mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) cnt++;
                }
                i++;
            } 
            j++;
        }
        return indx == -1 ? "" : s.substr(indx, mini);
    }
};