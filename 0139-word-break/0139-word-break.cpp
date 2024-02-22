class Solution {
public:
    int n;
    bool recursion(string s, vector<string> &dictionary, unordered_set<string>& st, int indx){
        if (indx >= n) return true;
        for (int i=indx; i<n; i++){
            string str = s.substr(indx, i-indx+1);
            if (st.find(str) != st.end()){
                if (recursion(s, dictionary, st, i+1)) return true;
            }
        }
        return false;
    }
    int memoization(string s, vector<string> &dictionary, unordered_set<string>& st, int indx, vector<int>& dp){
        if (indx >= n) return true;
        if (dp[indx] != -1) return dp[indx];
        for (int i=indx; i<n; i++){
            string str = s.substr(indx, i-indx+1);
            if (st.find(str) != st.end()){
                if (memoization(s, dictionary, st, i+1, dp)) return dp[indx] = true;
            }
        }
        return dp[indx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        vector<int> dp(n,-1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());;
        return memoization(s, wordDict, st, 0, dp);
    }
};