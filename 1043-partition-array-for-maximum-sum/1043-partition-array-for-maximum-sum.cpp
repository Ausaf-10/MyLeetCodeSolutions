class Solution {
public:
    int n;
    int recursion(vector<int>& arr, int indx, int k){
        if (indx >= arr.size()) return 0;
        int maxi = -1, s = 0;
        for (int i=indx; i<arr.size() && i<indx+k; i++){
            maxi = max(maxi, arr[i]);
            s = max(s,maxi*(i-indx+1) + recursion(arr, i+1, k));
        }
        return s;
    }
    int memoization(vector<int>& arr, int indx, int k, vector<int>& dp){
        if (indx >= n) return 0;
        if (dp[indx] != -1) return dp[indx];
       
        int maxi = -1, s = 0;
       
        for (int i=indx; i<n && i-indx+1<=k; i++){
            maxi = max(maxi, arr[i]);
            s = max(s,(maxi*(i-indx+1)) + memoization(arr, i+1, k, dp));
        }
        return dp[indx] = s;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> dp(n,-1);
        return memoization(arr, 0, k, dp);
    }
};