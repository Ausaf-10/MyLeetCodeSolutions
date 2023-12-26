int mod = 1e9+7;
class Solution {
public:
    int recursion(int n, int k, int target){
        if (target == 0) return 1;
        if (n == 0) return target == 0;
        long long ans = 0;
        for (int i=1; i<=k; i++){
            ans = ( (ans%mod) + (recursion(n-1,k,target-i)%mod) ) % mod;
        }
        return ans;
    }

    int memoization(int n, int k, int target, vector<vector<int>>& memoizationDP){
        if (target == 0 && n == 0) return  memoizationDP[n][target] = 1;
        if (n == 0 || target <= 0) return memoizationDP[n][target] = 0;
        
        if (memoizationDP[n][target]!=-1) return memoizationDP[n][target];
        
        long long ans = 0;
        for (int i=1; i<=k; i++){
            if (i > target) continue;            
            ans = ((ans%mod) + (memoization(n-1,k,target-i,memoizationDP)%mod)) % mod;
        }
        return memoizationDP[n][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memoizationDP(n+1, vector<int>(target+1,-1));
        return memoization(n,k,target,memoizationDP);
    }
};