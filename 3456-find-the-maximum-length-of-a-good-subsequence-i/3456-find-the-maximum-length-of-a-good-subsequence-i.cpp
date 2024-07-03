class Solution {
public:
    int k, n;
    int dp[501][501][26];
    int dfs(int indx, int prevIndx, int cnt, vector<int>& arr){
        if (indx == n) return 0;
        int pick = -1e9;
        if (prevIndx == -1 || arr[indx] == arr[prevIndx]){
            pick = 1 + dfs(indx+1, indx, cnt, arr);
        }
        if (prevIndx!=-1 && arr[prevIndx] != arr[indx]){
            if (cnt < k){
                pick = 1 + dfs(indx+1, indx, cnt+1, arr);
            }
        }
        int notPick = dfs(indx+1, prevIndx, cnt, arr);
        return max(pick, notPick);
    }
    int memoization(int indx, int prevIndx, int cnt, vector<int>& arr){
        if (indx == n) return 0;
        if (dp[indx][prevIndx+1][cnt] != -1) return dp[indx][prevIndx+1][cnt];
        int pick = -1e9;
        if (prevIndx == -1 || arr[indx] == arr[prevIndx]){
            pick = 1 + memoization(indx+1, indx, cnt, arr);
        }
        if (prevIndx!=-1 && arr[prevIndx] != arr[indx]){
            if (cnt < k){
                pick = 1 + memoization(indx+1, indx, cnt+1, arr);
            }
        }
        int notPick = memoization(indx+1, prevIndx, cnt, arr);
        return dp[indx][prevIndx+1][cnt] = max(pick, notPick);
    }
    int maximumLength(vector<int>& arr, int K) {
        n = arr.size(), k = K;
        memset(dp, -1, sizeof(dp));
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(k+1, -1))); 
        return memoization(0, -1, 0, arr);
    }
};