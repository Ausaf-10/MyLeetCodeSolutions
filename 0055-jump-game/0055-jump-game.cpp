class Solution {
public:
    int n;
    bool recursion(int indx, vector<int>& arr){
        if (indx == n-1) return true;
        for (int i=1; i<=arr[indx]; i++){
            if (indx + i < n && recursion(indx+i, arr)) return true;
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
    bool canJump(vector<int>& arr) {
        n = arr.size();
        vector<int> dp(n, -1);
        return memoization(0, arr, dp);
    }
};