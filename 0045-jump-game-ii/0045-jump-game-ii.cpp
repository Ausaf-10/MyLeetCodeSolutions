class Solution {
public:
    int n;
    int solve(int indx, vector<int>& arr){
        if (indx == n-1) return 0;
        if (arr[indx] == 0) return 1e9;
        int mini = 1e9;
        for (int i=1; i<=arr[indx]; i++){
            if (indx + i < n){
                mini = min(mini, 1 + solve(indx+i, arr));
            }
        }
        return mini;
    }
    int memoization(int indx, vector<int>& arr, vector<int>& dp){
        if (indx == n-1) return 0;
        if (arr[indx] == 0) return 1e9;
        if (dp[indx]!=-1) return dp[indx];
        int mini = 1e9;
        for (int i=1; i<=arr[indx]; i++){
            if (indx + i < n){
                mini = min(mini, 1 + memoization(indx+i, arr, dp));
            }
        }
        return dp[indx] = mini;
    }
    int jump(vector<int>& arr) {
        n = arr.size();
        vector<int> dp(n, -1);
        return memoization(0, arr, dp);
    }
};