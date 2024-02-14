class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for (int i=0; i<s.size(); i++){
            unordered_map<char, int> mp;
            for (int j=i; j<n; j++){
                int maxi = -1, mini=501;
                mp[s[j]]++;
                for (auto it : mp){
                    maxi = max(maxi, (int)it.second);
                    mini = min(mini, (int)it.second);
                }
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};