class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(), cnt = 0, maxi = 0;
        unordered_map<char, int> mp;
        while (j<n){
            mp[s[j]]++;
            while (mp.size() < (j-i+1) && i<j){
                mp[s[i]]--;          
                if (mp[s[i]] == 0) mp.erase(s[i]);      
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }
        return maxi;
    }
};