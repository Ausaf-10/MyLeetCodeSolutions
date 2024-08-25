class Solution {
public:
    int n;
    bool recursion(int indx, vector<int>& arr){
        if (indx == n-1) return true;
        for (int i=indx+1; i <= indx + arr[indx]; i++){
            if (i < n && recursion(i, arr)) return true;
        }
        return false;
    }
    bool memoization(int indx, vector<int>& arr, vector<int> &dp){
        if (indx == n-1) return true;
        if (dp[indx]!=-1) return dp[indx];
        for (int i=1; i<=arr[indx]; i++){
            if (indx + i < n && memoization(indx+i, arr, dp)) return dp[indx] = true;
        }
        return dp[indx] = false;
    }
    bool tabulation(vector<int>& arr){
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        for (int indx=n-2; indx>=0; indx--){
            if (arr[indx] == 0) continue;
            for (int i=indx+1; i <= indx + arr[indx]; i++){
                if (i < n && dp[i]) dp[indx] = true;
            }
        }
        return dp[0];
    }
    bool canJump(vector<int>& arr) {
        n = arr.size();
        // return recursion(0, arr);
        return tabulation(arr);
    }
};