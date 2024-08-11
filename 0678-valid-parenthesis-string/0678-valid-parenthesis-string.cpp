class Solution {
public:
    int n;
    bool recursion(int indx, int open, string& s){
        if (indx == n) return open == 0;
        if (s[indx] == '(') return recursion(indx+1, open+1, s);
        else if (s[indx] == ')'){
            if (open == 0) return false;
            return recursion(indx+1, open-1, s);
        }
        else{
            bool option1 = recursion(indx+1, open, s);       // empty character
            bool option2 = recursion(indx+1, open+1, s);    //  open 
            bool option3 = false;                          // close
            if (open > 0) option3 = recursion(indx+1, open-1, s);
            return option1 || option2 || option3;
        }
    }

    bool memoization(int indx, int open, string& s, vector<vector<int>>& dp){
        if (indx == n) return open == 0;
        if (dp[indx][open]!=-1) return dp[indx][open];
        if (s[indx] == '(') return dp[indx][open] = memoization(indx+1, open+1, s, dp);
        else if (s[indx] == ')'){
            if (open == 0) return false;
            return dp[indx][open] = memoization(indx+1, open-1, s, dp);
        }
        else{
            bool option1 = memoization(indx+1, open, s, dp);       // empty character
            bool option2 = memoization(indx+1, open+1, s, dp);    //  open 
            bool option3 = false;                          // close
            if (open > 0) option3 = memoization(indx+1, open-1, s, dp);
            return dp[indx][open] = option1 || option2 || option3;
        }
    }
    
    bool checkValidString(string s) {
        n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return memoization(0, 0, s, dp);
    }
};