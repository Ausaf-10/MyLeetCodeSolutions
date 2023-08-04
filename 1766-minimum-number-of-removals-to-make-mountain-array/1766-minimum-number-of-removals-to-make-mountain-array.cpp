class Solution {
public:
    vector<int> longestIncreasingSubsequence(vector<int>& nums){
       int n = nums.size();
       vector<int> dp(n,1);
       for (int i=0; i<n; i++){
           for (int j=0; j<i; j++){
               if (nums[i] > nums[j] && dp[i] < dp[j] + 1){
                   dp[i] = dp[j] + 1;
               }
           }
       }
       
       return dp;
	}
	 
	vector<int> longestDecreasingSubsequence(vector<int>& nums){	       
	       int n = nums.size();
	       vector<int> dp(n,1);
	    for (int i=n-1; i>=0; i--){
            for (int j=n-1; j>i; j--){
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1){
                   dp[i] = dp[j] + 1;
                }
           }
       }
	       
	   return dp;
	}

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> LIS = longestIncreasingSubsequence(nums);
	    vector<int> LDS = longestDecreasingSubsequence(nums);

        vector<int> temp(n,0);
	    int maxi = 1;
	    for (int i=0; i<n; i++){
	        if (LIS[i] > 1 && LDS[i] > 1){
                temp[i] = LIS[i] + LDS[i] - 1;
                maxi = max(maxi, temp[i]);
            }
	        
	    }

        return n - maxi;
        
        // return cnt1 + cnt2;
    }
};