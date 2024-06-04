class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0, maxi = 0;
        unordered_map<char, int> mp;
        for (auto it : s) mp[it]++;
        int flag = 0;
        for (auto it : mp){
            int freq = it.second;
            if (freq&1){
                ans += freq-1;
                mp[it.first]-=freq-1;
                flag = 1;
            }
            else{
                ans+=freq;
            }
        }
        if (flag) return ans + 1;
        return ans;
    }
};