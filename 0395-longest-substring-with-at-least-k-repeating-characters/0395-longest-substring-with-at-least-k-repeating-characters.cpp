class Solution {
public:
    int getMaxUnique(string& s){
        unordered_map<char, int> mp;
        for (char ch : s) mp[ch]++;
        return (int)mp.size();
    }
    int checkFreq(unordered_map<char,int> mp, int k){
        for (auto it : mp){
            if (it.second < k) return false;
        }
        return true;
    }
    int longestSubstring(string s, int k) {
        int n = s.size(), maxi = 0;
        if (k == 1) return (int)s.size();
        int maxUnique =  getMaxUnique(s);
        for (int b=1; b<=maxUnique; b++){
            int i=0,j=0;
            unordered_map<char,int> mp;
            while (j < n){
                mp[s[j]]++;
                while (mp.size() > b){
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                if (checkFreq(mp,k)){
                    maxi = max(maxi, j-i+1);
                }
                j++;
            }
        }     
        return maxi;
    }
};