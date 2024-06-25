using ll = long long int;
class Solution {
public:
    int n;
    ll recursion(vector<int>& arr, int indx, int prev, int sign){
        if (indx >= n) return 0;
        if (prev == 0){
            return arr[indx] + recursion(arr, indx+1, !prev, sign);
        }
        ll pick = -1e9, notPick = -1e9;
        if (sign){ // positive sign hai peeche 
            pick = -arr[indx] + recursion(arr, indx+1, prev, !sign);
            notPick = arr[indx] + recursion(arr, indx+1, prev, sign);
        }
        if (!sign){
            pick = arr[indx] + recursion(arr, indx+1, prev, !sign);
            notPick = arr[indx] + recursion(arr, indx+1, prev, sign);
        }
        
        return max(pick, notPick); 
    }
    ll memoization(vector<int>& arr, int indx, int prev, int sign, vector<vector<vector<ll>>>& dp){
        if (indx >= n) return 0;
        if (dp[indx][prev][sign]!=-1) return dp[indx][prev][sign];
        if (prev == 0){
            return dp[indx][prev][sign] = arr[indx] + memoization(arr, indx+1, !prev, sign, dp);
        }
        ll pick = -1e9, notPick = -1e9;
        if (sign){ // positive sign hai peeche 
            pick = -arr[indx] + memoization(arr, indx+1, prev, !sign, dp);
            notPick = arr[indx] + memoization(arr, indx+1, prev, 1, dp);
        }
        if (!sign){
            pick = arr[indx] + memoization(arr, indx+1, prev, !sign, dp);
            notPick = arr[indx] + memoization(arr, indx+1, prev, 1, dp);
        }
        
        return dp[indx][prev][sign] = max(pick, notPick); 
    }
    long long maximumTotalCost(vector<int>& arr) {
        n = arr.size();   
        vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(2,-1)));
        return memoization(arr, 0, 0, 1, dp);
    }
};