class Solution {
public:
    int n;
    bool recursion(int indx, int open, string str){
        if (indx == n){
            if (open == 0) return true;
            return false;
        }
        if (str[indx] == '('){
            return recursion(indx+1, open+1, str);
        }
        else if (str[indx] == ')'){
            if (open > 0) return recursion(indx+1, open-1, str);
            return false;
        }
    
        bool openBracket = recursion(indx+1, open+1, str);
        bool closeBracket = false;
        if (open > 0) closeBracket = recursion(indx+1, open-1, str);
        bool empty = recursion(indx+1, open, str);
        return openBracket || closeBracket || empty;
        
    }

    bool memoization(int indx, int open, string str, vector<vector<int>>& dp){
        if (indx == n){
            if (open == 0) return true;
            return false;
        }
        
        if (dp[indx][open] != -1) return dp[indx][open];

        if (str[indx] == '('){
            return dp[indx][open] = memoization(indx+1, open+1, str, dp);
        }
        else if (str[indx] == ')'){
            if (open > 0) return dp[indx][open] = memoization(indx+1, open-1, str, dp);
            return false;
        }
    
        bool openBracket = memoization(indx+1, open+1, str, dp);
        bool closeBracket = false;
        if (open > 0) closeBracket = memoization(indx+1, open-1, str, dp);
        bool empty = memoization(indx+1, open, str, dp);
        return dp[indx][open] = openBracket || closeBracket || empty;
        
    }

    bool checkValidString(string str) {
        n = str.size();
        vector<vector<int>> dp(n, vector<int>(201, -1));
        return memoization(0, 0, str, dp);
        // return recursion(0,0,str);
    }
};