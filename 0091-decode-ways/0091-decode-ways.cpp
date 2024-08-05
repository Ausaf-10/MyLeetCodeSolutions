class Solution {
public:
    int n;
    int recursion(int indx, string& s, unordered_map<int, string> &mp){
        if (indx == n) return 1;
        if (s[indx] == '0') return 0;
        int ans = 0;
        for (int i=indx; i<indx+2 && i<n; i++){
            string str = s.substr(indx, i-indx+1);
            int number = stoi(str);
            if (mp.find(number) == mp.end()) continue;
            ans = ans + recursion(i+1, s, mp);
        }
        return ans;
    }
    int memoization(int indx, string& s, unordered_map<int, string> &mp, vector<int> &dp){
        if (indx == n) return 1;
        if (s[indx] == '0') return 0;
        if (dp[indx] != -1) return dp[indx];
        int ans = 0;
        for (int i=indx; i<indx+2 && i<n; i++){
            string str = s.substr(indx, i-indx+1);
            int number = stoi(str);
            if (mp.find(number) == mp.end()) continue;
            ans = ans + memoization(i+1, s, mp, dp);
        }
        return dp[indx] = ans;
    }
    int numDecodings(string s) {
        n = s.size();
        unordered_map<int, string> mp;
        for (int i=1; i<=26; i++){
            char ch = (i-1) + 'A';
            string str;
            str.push_back(ch);
            mp[i] = str;
        }
        vector<int> dp(n, -1);
        return memoization(0, s, mp, dp);
    }
};