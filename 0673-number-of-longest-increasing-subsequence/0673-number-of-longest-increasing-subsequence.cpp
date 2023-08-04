class Solution {
public:
    int tabulation(vector<int>& nums){
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n,1), cnt(n,1);
        for (int i=0; i<n; i++){
            for (int prevIndx = 0; prevIndx<i; prevIndx++){
                if (nums[i] > nums[prevIndx] && dp[i] < dp[prevIndx] + 1){
                    cnt[i] = cnt[prevIndx];
                    dp[i] = dp[prevIndx] + 1;
                }
                else if (nums[i] > nums[prevIndx] && dp[i] == dp[prevIndx] + 1){
                    cnt[i]+=cnt[prevIndx];
                }
                
            }
            maxi = max(maxi, dp[i]);
        }

        int nos = 0;
        for (int i=0; i<n; i++){ 
            if (dp[i]==maxi){ 
                nos+=cnt[i];
            }
        }
        return nos;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return tabulation(nums);
    }
};