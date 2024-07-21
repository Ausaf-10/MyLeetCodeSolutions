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
    int tabulation(vector<int>& arr){
        vector<int> dp(n, 1e9);
        dp[n-1] = 0;
        for (int indx=n-2; indx>=0; indx--){
            if (arr[indx] == 0) continue;
            int mini = 1e9;
            for (int i=1; i<=arr[indx]; i++){
                if (indx + i < n){
                    mini = min(mini, 1 + dp[indx+i]);
                }
            }
            dp[indx] = mini;
        }
        return dp[0];
    }
    int jump(vector<int>& arr) {
        n = arr.size();
        // return memoization(0, arr, dp);
        return tabulation(arr);
    }
};