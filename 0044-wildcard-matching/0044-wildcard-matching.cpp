class Solution {
public:
    bool recursion(int i, int j, string& pattern, string& text){
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        
        if (i >=0 && j < 0){
            for (int indx = i; indx>=0; indx--){
                if (pattern[indx]!='*') return false;
            }
            return true;
        }

        if (pattern[i] == text[j] || pattern[i] == '?'){
            return recursion(i-1, j-1, pattern, text);
        }
        if (pattern[i] == '*'){
            return recursion(i, j-1, pattern, text) || recursion(i-1, j, pattern, text);
        }

        return false;
    }

    bool memoization(int i, int j, string& pattern, string& text, vector<vector<int>>& dp){
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        
        if (i >=0 && j < 0){
            for (int indx = i; indx>=0; indx--){
                if (pattern[indx]!='*') return false;
            }
            return true;
        }

        if (dp[i][j]!=-1) return dp[i][j];

        if (pattern[i] == text[j] || pattern[i] == '?'){
            return  dp[i][j] = memoization(i-1, j-1, pattern, text,dp);
        }
        if (pattern[i] == '*'){
            return dp[i][j] = memoization(i, j-1, pattern, text, dp) || memoization(i-1, j, pattern, text, dp);
        }

        return  dp[i][j] = false;
    }

    bool isMatch(string text, string pattern) {
        int n = pattern.size(), m = text.size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        
        return memoization(n-1, m-1, pattern, text, dp);
    }
};