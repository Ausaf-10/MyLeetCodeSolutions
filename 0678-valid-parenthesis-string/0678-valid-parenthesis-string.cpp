class Solution {
public:
    int n;
    bool solve(int indx, int open, string& s){
        if (indx >= n){
            if (open == 0) return true;
            return false;
        }
        char ch = s[indx];
        bool left = false, right = false, up = false;
        if (ch == '('){
            left = solve(indx+1, open+1, s);
        }
        else if (ch == ')'){
            if (open > 0){
                right = solve(indx+1, open-1, s);
            }
        }
        else{
            left = solve(indx+1, open+1, s);
            if (open > 0){
                right = solve(indx+1, open-1, s);
            }
            up = solve(indx+1, open, s);
        }
        return left || up || right;
    }
    
    bool tabulation(string& s){
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        dp[n][0] = true;
        for (int indx=n-1; indx>=0; indx--){
            for (int open = 0; open<=n; open++){
                char ch = s[indx];
                bool left = false, right = false, up = false;
                if (ch == '('){
                    left = dp[indx+1][open+1];
                }
                else if (ch == ')'){
                    if (open > 0){
                        right = dp[indx+1][open-1];
                    }
                }
                else{
                    left = dp[indx+1][open+1];
                    if (open > 0){
                        right = dp[indx+1][open-1];
                    }
                    up = dp[indx+1][open];
                }
                dp[indx][open] = left || up || right;
            }
        }
        return dp[0][0];
    }

    bool checkValidString(string s) {
        n = s.size();
        // return solve(0, 0, s);
        return tabulation(s);
    }
};