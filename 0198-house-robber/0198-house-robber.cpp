class Solution {
public:
    // indx:  n-1 -> 0
    int recursion(int indx, vector<int>& arr){
        if (indx == 0) return arr[0];
        int pick = arr[indx];
        if (indx > 1) pick+=recursion(indx-2,arr);
        int notPick = 0 + recursion(indx-1, arr);
        return max(pick, notPick);
    }
    
    int memoization(int indx, vector<int>& arr, vector<int>& dp){
        if (indx == 0) return arr[0];
        if (dp[indx]!=-1) return dp[indx];
        
        int pick = arr[indx];
        if (indx > 1) pick+=recursion(indx-2,arr);
        int notPick = 0 + recursion(indx-1, arr);
        
        return dp[indx] = max(pick, notPick);
    }
    
    int tabulation(vector<int> arr, int n){
        vector<int> dp(n,0);
        dp[0] = arr[0];         // BASE CASE
        // NOW BOTTOM-UP, REVERSE OF RECURSION
        for (int indx=1; indx<n; indx++){
             int pick = arr[indx];
            if (indx > 1) pick+= dp[indx-2];
            int notPick = 0 + dp[indx-1];
            
            dp[indx] = max(pick, notPick);
        }
        return dp[n-1];
    }
    
    int spaceOptimisation(vector<int> arr, int n){
        int prev = arr[0], prev2 = 0;
        for (int i = 1; i < n; i++){
            int pick = arr[i];
            if (i > 1) pick += prev2;
            int notPick = 0 + prev;
            int cur = max(pick,notPick);
            prev2 = prev, prev = cur; 
        }

        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n,-1);
        return spaceOptimisation(nums, n);
    }
};